//
//  InternalTypes.hpp
//  fvm
//
//  Created by Chunghee Lee on 5/6/18.
//  Copyright © 2018 Chunghee Lee. All rights reserved.
//

#ifndef InternalTypes_hpp
#define InternalTypes_hpp

#include <stdio.h>
#include "opcode.hpp"
#include "InternalTypes.hpp"
#include "FvmObject.hpp"

typedef struct _EXECUTIONRESULT
{
    int64_t EllapsedMillis;
    int64_t NumOfExecutedCpCodes;
    int64_t NumOfUsedGas;
    bool bTerminated;
    bool bException;
} EXECUTIONRESULT;

class FvmObject;

union MULTI64
{
    int64_t INT;
    double DOUBLE;
    FvmObject *OBJ;
};

typedef struct _INSTRUCTION
{
    OPCODE opcode;
    MULTI64 operand[3];
} INSTRUCTION;

#endif /* InternalTypes_hpp */
