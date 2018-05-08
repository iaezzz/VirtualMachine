//
//  VirtualMachine.hpp
//  fvm
//
//  Created by Fantom Foundation
//  Copyright © 2018 Fantom Foundation. All rights reserved.
//


#ifndef VirtualMachine_hpp
#define VirtualMachine_hpp

#include <vector>
#include "InternalTypes.hpp"
#include "MemoryManager.hpp"
#include "SystemInterface.hpp"
#include "FvmObjectManager.hpp"

#define OPCODE_IMPL_DECL(opcode, op1, op2) \
void opcode##_##op1##_##op2()

class VirtualMachine
{
private:
    int64_t programCounter = 0;
    int64_t opcodeCounter = 0;
    int64_t gasCounter = 0;

    std::vector<INSTRUCTION> programVector;
    std::vector<std::vector<MULTI64>> registerVectorStack;
    std::vector<int64_t> callStackVactor;

    MULTI64 returnedValue;

    OPCODE_IMPL_DECL(NOP,,);
    OPCODE_IMPL_DECL(MOV1,reg4,reg4);
    OPCODE_IMPL_DECL(MOV2,reg4,val8);
    OPCODE_IMPL_DECL(MOV3,reg4,val16);
    OPCODE_IMPL_DECL(MOV4,reg4,val32);
    OPCODE_IMPL_DECL(MOV5,reg4,val64);
    OPCODE_IMPL_DECL(ADD1,reg4,reg4);
    OPCODE_IMPL_DECL(ADD2,reg8,reg8);
    
public:
    bool bTerminated = false;
    bool bDebugMode = false;
    
    std::unique_ptr<MemoryManager> memoryManager = std::make_unique<MemoryManager>();
    std::unique_ptr<SystemInterface> systemInterface = std::make_unique<SystemInterface>();
    std::unique_ptr<FvmObjectManager> objectManager = std::make_unique<FvmObjectManager>();
    
    VirtualMachine();
    void Initialize();
    void LoadOpCode(std::istream& is);
    void PushRegisters();
    
    EXECUTIONRESULT Execute();
    
protected:
    
};


#endif /* VirtualMachine_hpp */
