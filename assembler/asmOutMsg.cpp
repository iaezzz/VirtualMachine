//
//  asmOutMsg.cpp
//  asmFVM
//
//  Created by Yousung Cha on 5/8/18.
//  Copyright © 2018 Fantom Foundation. All rights reserved.
//

#include "asmDefine.h"
#include "asmFunc.h"
#include "asmOutMsg.h"

void printHelpSet()
{
	cout << "Usage: asmFVM <command>" << endl << endl;
	cout << "where <command> is onf of:" << endl;
	cout << "\t--inl, --asm, --dsm" << endl << endl;
	cout << "asmFVM <cmd> --inl\t\t\tin-line assemble mode" << endl;
	cout << "asmFVM <cmd> --asm <filename.asm>\tfile assemble mode" << endl;
	cout << "asmFVM <cmd> --dsm <filename.bin>\tfile disassemble mode" << endl;
}

void printError(string cmd, int errArg)
{
	switch (errArg)
	{
	case (int)errList::NoCommand:
		cout << "asmFVM System Error : (" << cmd << ") command not found" << endl;
		break;
	case (int)errList::NoFileName:
		cout << "asmFVM System Error : (" << cmd << ") requires a file name as an argument. " << endl;
		break;
	case (int)errList::NoFile:
		cout << "asmFVM System Error : " << cmd << " does not exist." << endl;
		break;
	default:
		break;
	}	
}

void printOpCodeError(int commandLine, string cmd, int errArg)
{
	cout << "ERROR \n\n--------------------------------------------------------" << endl;
	cout << "\n *** Assemble Error" << endl;
	switch (errArg)
	{
	case (int)errList::NoOpCommand:
		cout << "\n  Ln " << std::right << std::setw(2) << std::setfill('0') << commandLine << " : " << cmd << " command is not recognized." << endl;
		break;
	case (int)errList::InCorrectFormat:
		cout << "\n  Ln " << std::right << std::setw(2) << std::setfill('0') << commandLine << " : The format of the arguments is incorrect." << endl;
		break;
	case (int)errList::ContainSpace:
		cout << "\n  Ln " << std::right << std::setw(2) << std::setfill('0') << commandLine << " : Command can not contain spaces." << endl;
		break;
	default:
		break;
	}
	cout << "\n--------------------------------------------------------" << endl;
}

void printAssembleSuccess(string outputFileName)
{
	cout << "\n--------------------------------------------------------" << endl;
	cout << "\n *** Assemble Success" << endl;
	cout << "\n  Output File Name : " << outputFileName << endl;
	cout << "\n--------------------------------------------------------" << endl << endl;
}

void printLnCommand(unsigned int ln, string cmd, int pad)
{
	cout << "   Ln " << std::setw(2) << std::setfill('0') << ln << " : " << "(" << std::left << std::setfill(' ') << std::setw(pad) << cmd << ") - ";
}

void systemDelay(int ms)
{
	auto realTime = ms * 300000;
	for (int i = 0; i < realTime; i++);
}