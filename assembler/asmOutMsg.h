//
//  asmOutMsg.h
//  asmFVM
//
//  Created by Yousung Cha on 5/8/18.
//  Copyright © 2018 Fantom Foundation. All rights reserved.
//

#pragma once
#include "asmDefine.h"
#include "asmFunc.h"

void printHelpSet();
void printError(string cmd, int errArg);
void printOpCodeError(int commandLine, string cmd, int errArg);
void printAssembleSuccess(string outputFileName);
void systemDelay(int ms);
void printLnCommand(unsigned int ln, string cmd, int pad);