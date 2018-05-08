//
//  main.cpp
//  asmFVM
//
//  Created by Yousung Cha on 5/8/18.
//  Copyright © 2018 Fantom Foundation. All rights reserved.
//

#include "asmDefine.h"
#include "asmFunc.h"
#include "asmOutMsg.h"

int main(int argc, char** argv)
{
	std::vector <string> args(argv, argv + argc);
	string command = (argc >= 2) ? argv[1] : "null";
	string fileName = (argc == 3) ? argv[2] : "null";
	unsigned int cmdLine = 0;
		
	// No Command (Instruction set)
	if (argc == (int)sysCommand::NoCommand) printHelpSet();

	// In-Line Mode
	else if (argc == (int)sysCommand::InLineMode)
	{					
		
		if (command == "--asm") printError(command, (int)errList::NoFileName);
		else if (command == "--dsm") printError(command, (int)errList::NoFileName);
		else if (command == "--inl")
		{
			cout << "in-line command mode." << endl;
			// this will be implemented in future.
		}
		else printError(command, (int)errList::NoCommand);
	}

	// ASM - DSM Mode
	else if (argc == (int)sysCommand::OtherMode)
	{		
		if (command == "--asm")
		{
			string data, dest;
			ifstream infile(fileName);
			if (infile)
			{
				cout << ">> Start assembling the " << fileName << " file..." << endl << endl;
				while (!infile.eof() && (cmdLine != -1))
				{
					getline(infile, data);
					assembler(&cmdLine, data, &dest);
					systemDelay(50);
				}
				infile.close();
				if (dest != "")
				{					
					string outputFileName = fileName.substr(0, fileName.length() - 4);
					outputFileName += ".bin";
					cout << endl << ">> All lines have been successfully assembled." << endl;
					printAssembleSuccess(outputFileName);
					std::ofstream out(outputFileName, std::ios::binary);
					out << dest;
					out.close();
				}
				else cout << endl << ">> Bin file creation failed due to an error." << endl << endl;
			}
			else printError(fileName, (int)errList::NoFile);
		}
		else if (command == "--dsm")
		{
			cout << "disassemble command mode." << endl;
			// this will be implemented in future.
		}
		else if (command == "--inl")
		{
			cout << "in-line command mode." << endl;
			// this will be implemented in future.
		}
		else printError(command, (int)errList::NoCommand);
	}
    return 0;
}