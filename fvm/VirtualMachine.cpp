//
//  VirtualMachine.cpp
//  fvm
//
//  Created by Fantom Foundation
//  Copyright © 2018 Fantom Foundation. All rights reserved.
//

#include <istream>
#include <iostream>
#include "VirtualMachine.hpp"
#include "opcode.hpp"

VirtualMachine::VirtualMachine() {
    Initialize();
    OpcodeUtil::GetInstance();
};

// We're currently supporting big endian only.

void VirtualMachine::LoadOpCode(std::istream &is) {
    Initialize();
    auto &o = OpcodeUtil::GetInstance();
    char opcode;
    char buf=0;
    long val;
    
    while(is.read(&opcode, 1))
    {
        auto ins = INSTRUCTION{};
        
        ins.opcode = static_cast<OPCODE>(opcode);
        val = 0;
        for(auto i=0; i<3; i++)
        {
            if (o.aOpcode[opcode].optype[i] == OPERAND_TYPE::reg_4 ||
                o.aOpcode[opcode].optype[i] == OPERAND_TYPE::ref_reg_4)
            {
                is.read(&buf, 1);
                ins.operand[i].INT = (buf >> 4) & 0x0f;
                ins.operand[i+1].INT = buf & 0x0f;
                i++;
            } else
            {
                val = 0;
                for(auto j=0; j<o.aOpcode[opcode].oplen[i]; j++)
                {
                    is.read(&buf, 1);
                    val = (val << 8) | (buf & 0xff);
                }
                ins.operand[i].INT = val;
            }
        }
        
        programVector.push_back(ins);
        
        if(bDebugMode)
            printf("Loading %02x : %02llx %02llx %02llx\n", opcode, ins.operand[0].INT, ins.operand[1].INT, ins.operand[2].INT);
    }
};

EXECUTIONRESULT VirtualMachine::Execute() {
    EXECUTIONRESULT ret;
    auto& registerVector = registerVectorStack.back();
    
    int64_t nextProgramCounter = programCounter + 1;
    try
    {
        const INSTRUCTION& ins = programVector.at(programCounter);

        switch (ins.opcode)
        {
            case OPCODE::nop:
                break;

            case OPCODE::halt:
                bTerminated = true;
                break;

            case OPCODE::mov_reg4_reg4:
            case OPCODE::mov_reg8_reg8:
                registerVector.at(ins.operand[0].INT) = registerVector.at(ins.operand[1].INT);
                break;
                
            case OPCODE::mov_reg8_val8:
            case OPCODE::mov_reg8_val16:
            case OPCODE::mov_reg8_val32:
            case OPCODE::mov_reg8_val64:
                registerVector.at(ins.operand[0].INT) = ins.operand[1];
                break;
                
            case OPCODE::addi_reg4_reg4:
            case OPCODE::addi_reg8_reg8:
                registerVector.at(ins.operand[0].INT).INT += registerVector.at(ins.operand[1].INT).INT;
                break;
                
            case OPCODE::subi_reg4_reg4:
            case OPCODE::subi_reg8_reg8:
                registerVector.at(ins.operand[0].INT).INT -= registerVector.at(ins.operand[1].INT).INT;
                break;

            case OPCODE::muli_reg4_reg4:
            case OPCODE::muli_reg8_reg8:
                registerVector.at(ins.operand[0].INT).INT *= registerVector.at(ins.operand[1].INT).INT;
                break;

            // Todo: div_by_zero will be handled soon.
            case OPCODE::divi_reg4_reg4:
            case OPCODE::divi_reg8_reg8:
                registerVector.at(ins.operand[0].INT).INT /= registerVector.at(ins.operand[1].INT).INT;
                break;

            case OPCODE::modi_reg4_reg4:
            case OPCODE::modi_reg8_reg8:
                registerVector.at(ins.operand[0].INT).INT %= registerVector.at(ins.operand[1].INT).INT;
                break;
                
            case OPCODE::addf_reg4_reg4:
            case OPCODE::addf_reg8_reg8:
                registerVector.at(ins.operand[0].INT).DOUBLE += registerVector.at(ins.operand[1].INT).DOUBLE;
                break;
                
            case OPCODE::subf_reg4_reg4:
            case OPCODE::subf_reg8_reg8:
                registerVector.at(ins.operand[0].INT).DOUBLE -= registerVector.at(ins.operand[1].INT).DOUBLE;
                break;
                
            case OPCODE::mulf_reg4_reg4:
            case OPCODE::mulf_reg8_reg8:
                registerVector.at(ins.operand[0].INT).DOUBLE *= registerVector.at(ins.operand[1].INT).DOUBLE;
                break;
                
                // Todo: div_by_zero will be handled soon.
            case OPCODE::divf_reg4_reg4:
            case OPCODE::divf_reg8_reg8:
                registerVector.at(ins.operand[0].INT).DOUBLE /= registerVector.at(ins.operand[1].INT).DOUBLE;
                break;
                
            case OPCODE::jmp_eq_reg4_reg4_val16:
            case OPCODE::jmp_eq_reg8_reg8_val16:
            case OPCODE::jmp_eq_reg4_reg4_val32:
            case OPCODE::jmp_eq_reg8_reg8_val32:
                nextProgramCounter = registerVector.at(ins.operand[0].INT).INT ==
                registerVector.at(ins.operand[1].INT).INT ? programCounter + ins.operand[2].INT : nextProgramCounter;
                break;
                
            case OPCODE::jmp_ne_reg4_reg4_val16:
            case OPCODE::jmp_ne_reg8_reg8_val16:
            case OPCODE::jmp_ne_reg4_reg4_val32:
            case OPCODE::jmp_ne_reg8_reg8_val32:
                nextProgramCounter = registerVector.at(ins.operand[0].INT).INT !=
                registerVector.at(ins.operand[1].INT).INT ? programCounter + ins.operand[2].INT : nextProgramCounter;
                break;
                
            case OPCODE::jmp_gt_reg4_reg4_val16:
            case OPCODE::jmp_gt_reg8_reg8_val16:
            case OPCODE::jmp_gt_reg4_reg4_val32:
            case OPCODE::jmp_gt_reg8_reg8_val32:
                nextProgramCounter = registerVector.at(ins.operand[0].INT).INT >
                registerVector.at(ins.operand[1].INT).INT ? programCounter + ins.operand[2].INT : nextProgramCounter;
                break;
                
            case OPCODE::jmp_ge_reg4_reg4_val16:
            case OPCODE::jmp_ge_reg8_reg8_val16:
            case OPCODE::jmp_ge_reg4_reg4_val32:
            case OPCODE::jmp_ge_reg8_reg8_val32:
                nextProgramCounter = registerVector.at(ins.operand[0].INT).INT >=
                registerVector.at(ins.operand[1].INT).INT ? programCounter + ins.operand[2].INT : nextProgramCounter;
                break;
                
            case OPCODE::jmp_lt_reg4_reg4_val16:
            case OPCODE::jmp_lt_reg8_reg8_val16:
            case OPCODE::jmp_lt_reg4_reg4_val32:
            case OPCODE::jmp_lt_reg8_reg8_val32:
                nextProgramCounter = registerVector.at(ins.operand[0].INT).INT <
                registerVector.at(ins.operand[1].INT).INT ? programCounter + ins.operand[2].INT : nextProgramCounter;
                break;
                
            case OPCODE::jmp_le_reg4_reg4_val16:
            case OPCODE::jmp_le_reg8_reg8_val16:
            case OPCODE::jmp_le_reg4_reg4_val32:
            case OPCODE::jmp_le_reg8_reg8_val32:
                nextProgramCounter = registerVector.at(ins.operand[0].INT).INT <=
                registerVector.at(ins.operand[1].INT).INT ? programCounter + ins.operand[2].INT : nextProgramCounter;
                break;

            // Object-Oriented Related Feature
            case OPCODE::new_val8_val8_val8:
            case OPCODE::new_val16_val8_val8:
            case OPCODE::call_static_val8_val8_val8:
            case OPCODE::call_dynamic_ref8_val8_val8_val8:
            case OPCODE::load_reg8_ref8_val8:
            case OPCODE::load_reg8_ref8_val16:
            case OPCODE::store_reg8_ref8_val8:
            case OPCODE::store_reg8_ref8_val16:
                break;

            case OPCODE::ret_reg8:
                returnedValue = registerVector.at(ins.operand[0].INT);
            case OPCODE::ret_val8:
            case OPCODE::ret_val16:
            case OPCODE::ret_val32:
            case OPCODE::ret_val64:
                returnedValue.INT = ins.operand[0].INT;
                nextProgramCounter = callStackVactor.back();
                callStackVactor.pop_back();
                break;
            case OPCODE::movret_reg8:
                registerVector.at(ins.operand[0].INT) = returnedValue;
                break;

            default:
                throw std::exception(); // not implemented opcode
        }
    
        if(bDebugMode)
        {
            printf("Opcode: %02x %02llx %02llx %02llx , ProgramCounter: %lld , NextProgramCounter: %lld\n", ins.opcode, ins.operand[0].INT, ins.operand[1].INT, ins.operand[2].INT, programCounter, nextProgramCounter);
            
            for(auto i=0; i<16; i++)
            {
                printf("r%d:%08llx ", i, registerVector[i].INT);
            }
            printf("\n");
        }
    }
    catch(std::exception& e)
    {
        if (bDebugMode)
            printf("Error on %s \n", e.what());
        ret.bTerminated = true;
        ret.bException = true;
        return ret;
    }
    catch(...)
    {
       if (bDebugMode)
           printf("Unhandled execption was caused during exection\n");
       ret.bTerminated = true;
       ret.bException = true;
       return ret;
    }
    
    programCounter = nextProgramCounter;
    
    if(programCounter >= programVector.size())
    {
        ret.bTerminated = true;
    }
    
    return ret;
};

void VirtualMachine::PushRegisters()
{
    registerVectorStack.push_back(std::vector<MULTI64>());
    registerVectorStack.back().resize(256);
}

void VirtualMachine::Initialize() {
    programCounter = 0;
    programVector.clear();
    registerVectorStack.clear();
    PushRegisters();
    callStackVactor.clear();
};
