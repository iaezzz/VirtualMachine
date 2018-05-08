//
//  asmDefine.h
//  asmFVM
//
//  Created by Yousung Cha on 5/8/18.
//  Copyright © 2018 Fantom Foundation. All rights reserved.
//

#pragma once
#include "asmDefine.h"

op assembler(unsigned int *commandLine, string data, string *dest);
op checkOpName(string opName, op *opValue);
void printBinaryData(op command);
void printBinaryData(op command, op oper1, op oper2);
void printBinaryData(op command, op oper1, op oper2, op oper3);
void writeBinaryData(string *dest, op command);
void writeBinaryData(string *dest, op command, op oper1, op oper2);
void writeBinaryData(string *dest, op command, op oper1, op oper2, op oper3);
void dataSerializer(op oper, string *dest);
