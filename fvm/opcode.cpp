//
//  opcode.cpp
//  fvm
//
//  Created by Fantom Foundation
//  Copyright © 2018 Fantom Foundation. All rights reserved.
//

#include "opcode.hpp"

OperandStruct OpcodeUtil::aOpcode[256];

OpcodeUtil::OpcodeUtil() {
    aOpcode[(int)OPCODE::nop] = OperandStruct(OPERAND_TYPE::none, OPERAND_TYPE::none);
    aOpcode[(int)OPCODE::mov_reg4_reg4] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4);
    aOpcode[(int)OPCODE::mov_reg8_reg8] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8);
    aOpcode[(int)OPCODE::mov_reg8_val8] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::val_8);
    aOpcode[(int)OPCODE::mov_reg8_val16] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::val_16);
    aOpcode[(int)OPCODE::mov_reg8_val32] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::val_32);
    aOpcode[(int)OPCODE::mov_reg8_val64] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::val_64);
    aOpcode[(int)OPCODE::addi_reg4_reg4] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4);
    aOpcode[(int)OPCODE::addi_reg8_reg8] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8);
    aOpcode[(int)OPCODE::subi_reg4_reg4] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4);
    aOpcode[(int)OPCODE::subi_reg8_reg8] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8);
    aOpcode[(int)OPCODE::muli_reg4_reg4] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4);
    aOpcode[(int)OPCODE::muli_reg8_reg8] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8);
    aOpcode[(int)OPCODE::divi_reg4_reg4] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4);
    aOpcode[(int)OPCODE::divi_reg8_reg8] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8);
    aOpcode[(int)OPCODE::modi_reg4_reg4] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4);
    aOpcode[(int)OPCODE::modi_reg8_reg8] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8);
    aOpcode[(int)OPCODE::addf_reg4_reg4] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4);
    aOpcode[(int)OPCODE::addf_reg8_reg8] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8);
    aOpcode[(int)OPCODE::subf_reg4_reg4] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4);
    aOpcode[(int)OPCODE::subf_reg8_reg8] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8);
    aOpcode[(int)OPCODE::mulf_reg4_reg4] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4);
    aOpcode[(int)OPCODE::mulf_reg8_reg8] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8);
    aOpcode[(int)OPCODE::divf_reg4_reg4] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4);
    aOpcode[(int)OPCODE::divf_reg8_reg8] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8);

    aOpcode[(int)OPCODE::jmp_eq_reg4_reg4_val16] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4, OPERAND_TYPE::val_16);
    aOpcode[(int)OPCODE::jmp_eq_reg8_reg8_val16] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8, OPERAND_TYPE::val_16);
    aOpcode[(int)OPCODE::jmp_eq_reg4_reg4_val32] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4, OPERAND_TYPE::val_32);
    aOpcode[(int)OPCODE::jmp_eq_reg8_reg8_val32] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8, OPERAND_TYPE::val_32);
    aOpcode[(int)OPCODE::jmp_ne_reg4_reg4_val16] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4, OPERAND_TYPE::val_16);
    aOpcode[(int)OPCODE::jmp_ne_reg8_reg8_val16] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8, OPERAND_TYPE::val_16);
    aOpcode[(int)OPCODE::jmp_ne_reg4_reg4_val32] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4, OPERAND_TYPE::val_32);
    aOpcode[(int)OPCODE::jmp_ne_reg8_reg8_val32] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8, OPERAND_TYPE::val_32);

    aOpcode[(int)OPCODE::jmp_gt_reg4_reg4_val16] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4, OPERAND_TYPE::val_16);
    aOpcode[(int)OPCODE::jmp_gt_reg8_reg8_val16] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8, OPERAND_TYPE::val_16);
    aOpcode[(int)OPCODE::jmp_gt_reg4_reg4_val32] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4, OPERAND_TYPE::val_32);
    aOpcode[(int)OPCODE::jmp_gt_reg8_reg8_val32] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8, OPERAND_TYPE::val_32);
    aOpcode[(int)OPCODE::jmp_ge_reg4_reg4_val16] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4, OPERAND_TYPE::val_16);
    aOpcode[(int)OPCODE::jmp_ge_reg8_reg8_val16] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8, OPERAND_TYPE::val_16);
    aOpcode[(int)OPCODE::jmp_ge_reg4_reg4_val32] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4, OPERAND_TYPE::val_32);
    aOpcode[(int)OPCODE::jmp_ge_reg8_reg8_val32] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8, OPERAND_TYPE::val_32);
    
    aOpcode[(int)OPCODE::jmp_lt_reg4_reg4_val16] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4, OPERAND_TYPE::val_16);
    aOpcode[(int)OPCODE::jmp_lt_reg8_reg8_val16] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8, OPERAND_TYPE::val_16);
    aOpcode[(int)OPCODE::jmp_lt_reg4_reg4_val32] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4, OPERAND_TYPE::val_32);
    aOpcode[(int)OPCODE::jmp_lt_reg8_reg8_val32] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8, OPERAND_TYPE::val_32);
    aOpcode[(int)OPCODE::jmp_le_reg4_reg4_val16] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4, OPERAND_TYPE::val_16);
    aOpcode[(int)OPCODE::jmp_le_reg8_reg8_val16] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8, OPERAND_TYPE::val_16);
    aOpcode[(int)OPCODE::jmp_le_reg4_reg4_val32] = OperandStruct(OPERAND_TYPE::reg_4, OPERAND_TYPE::reg_4, OPERAND_TYPE::val_32);
    aOpcode[(int)OPCODE::jmp_le_reg8_reg8_val32] = OperandStruct(OPERAND_TYPE::reg_8, OPERAND_TYPE::reg_8, OPERAND_TYPE::val_32);
}



