//
//  asmFunc.cpp
//  asmFVM
//
//  Created by Yousung Cha on 5/8/18.
//  Copyright © 2018 Fantom Foundation. All rights reserved.
//

#include "asmDefine.h"
#include "asmFunc.h"
#include "asmOutMsg.h"

op assembler(unsigned int *commandLine, string data, string *dest)
{	
	*commandLine = *commandLine + 1;
	if (data[0] != ' ' && data != "")
	{
		// parse string
		printLnCommand(*commandLine, data, 35);
		istringstream iss(data);
		vector<string> parsedCmd{ istream_iterator<string>{iss}, istream_iterator<string>{} };

		int commandLength = parsedCmd.size();
		int command = 0;
		op checkResult1 = 0, checkResult2 = 0, checkResult3 = 0;
		op oper1 = 0, oper2 = 0, oper3 = 0;		
		transform(parsedCmd.at(0).begin(), parsedCmd.at(0).end(), parsedCmd.at(0).begin(), toupper);

		// check main command
		if (parsedCmd[0] == "MOV") command = (int)prefOPCODE::mov;
		else if (parsedCmd[0] == "ADDI") command = (int)prefOPCODE::addi;
		else if (parsedCmd[0] == "SUBI") command = (int)prefOPCODE::subi;
		else if (parsedCmd[0] == "MULI") command = (int)prefOPCODE::muli;
		else if (parsedCmd[0] == "DIVI") command = (int)prefOPCODE::divi;
		else if (parsedCmd[0] == "MODI") command = (int)prefOPCODE::modi;
		else if (parsedCmd[0] == "JMP_EQ") command = (int)prefOPCODE::jmp_eq;
		else if (parsedCmd[0] == "JMP_NE") command = (int)prefOPCODE::jmp_ne;
		else if (parsedCmd[0] == "JMP_GT") command = (int)prefOPCODE::jmp_gt;
		else if (parsedCmd[0] == "JMP_GE") command = (int)prefOPCODE::jmp_ge;
		else if (parsedCmd[0] == "JMP_LT") command = (int)prefOPCODE::jmp_lt;
		else if (parsedCmd[0] == "JMP_LE") command = (int)prefOPCODE::jmp_le;
		else if (parsedCmd[0] == "NOP") command = (int)prefOPCODE::nop;
		else if (parsedCmd[0] == "HALT") command = (int)prefOPCODE::halt;
		else
		{
			printOpCodeError(*commandLine, parsedCmd[0], (int)errList::NoOpCommand);
			*commandLine = -1;
			*dest = "";
			return (op)errList::NoOpCommand;
		}

		// command processing
		if (command == (int)prefOPCODE::mov && commandLength == 3)
		{
			checkResult1 = checkOpName(parsedCmd[1], &oper1);
			checkResult2 = checkOpName(parsedCmd[2], &oper2);
			if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_4)
			{
				command = (int)OPCODE::mov_reg4_reg4;				
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_8)
			{
				command = (int)OPCODE::mov_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_4)
			{
				command = (int)OPCODE::mov_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::bit_8)
			{
				command = (int)OPCODE::mov_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_8)
			{
				command = (int)OPCODE::mov_reg8_val8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_16)
			{
				command = (int)OPCODE::mov_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_32)
			{
				command = (int)OPCODE::mov_reg8_val32;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);				
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_64)
			{
				command = (int)OPCODE::mov_reg8_val64;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else
			{
				printOpCodeError(*commandLine, "", (int)errList::InCorrectFormat);
				*commandLine = -1;
				*dest = "";
				return (op)errList::InCorrectFormat;
			}
		}
		else if (command == (int)prefOPCODE::addi && commandLength == 3)
		{
			checkResult1 = checkOpName(parsedCmd[1], &oper1);
			checkResult2 = checkOpName(parsedCmd[2], &oper2);
			if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_4)
			{
				command = (int)OPCODE::addi_reg4_reg4;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_8)
			{
				command = (int)OPCODE::addi_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_4)
			{
				command = (int)OPCODE::addi_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::bit_8)
			{
				command = (int)OPCODE::addi_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_8)
			{
				command = (int)OPCODE::addi_reg8_val8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_16)
			{
				command = (int)OPCODE::addi_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_32)
			{
				command = (int)OPCODE::addi_reg8_val32;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_64)
			{
				command = (int)OPCODE::addi_reg8_val64;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else
			{
				printOpCodeError(*commandLine, "", (int)errList::InCorrectFormat);
				*commandLine = -1;
				*dest = "";
				return (op)errList::InCorrectFormat;
			}
		}
		else if (command == (int)prefOPCODE::subi && commandLength == 3)
		{
			checkResult1 = checkOpName(parsedCmd[1], &oper1);
			checkResult2 = checkOpName(parsedCmd[2], &oper2);
			if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_4)
			{
				command = (int)OPCODE::subi_reg4_reg4;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_8)
			{
				command = (int)OPCODE::subi_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_4)
			{
				command = (int)OPCODE::subi_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::bit_8)
			{
				command = (int)OPCODE::subi_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_8)
			{
				command = (int)OPCODE::subi_reg8_val8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_16)
			{
				command = (int)OPCODE::subi_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_32)
			{
				command = (int)OPCODE::subi_reg8_val32;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_64)
			{
				command = (int)OPCODE::subi_reg8_val64;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else
			{
				printOpCodeError(*commandLine, "", (int)errList::InCorrectFormat);
				*commandLine = -1;
				*dest = "";
				return (op)errList::InCorrectFormat;
			}
		}
		else if (command == (int)prefOPCODE::muli && commandLength == 3)
		{
			checkResult1 = checkOpName(parsedCmd[1], &oper1);
			checkResult2 = checkOpName(parsedCmd[2], &oper2);
			if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_4)
			{
				command = (int)OPCODE::muli_reg4_reg4;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_8)
			{
				command = (int)OPCODE::muli_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_4)
			{
				command = (int)OPCODE::muli_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::bit_8)
			{
				command = (int)OPCODE::muli_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_8)
			{
				command = (int)OPCODE::muli_reg8_val8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_16)
			{
				command = (int)OPCODE::muli_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_32)
			{
				command = (int)OPCODE::muli_reg8_val32;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_64)
			{
				command = (int)OPCODE::muli_reg8_val64;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else
			{
				printOpCodeError(*commandLine, "", (int)errList::InCorrectFormat);
				*commandLine = -1;
				*dest = "";
				return (op)errList::InCorrectFormat;
			}
		}
		else if (command == (int)prefOPCODE::divi && commandLength == 3)
		{
			checkResult1 = checkOpName(parsedCmd[1], &oper1);
			checkResult2 = checkOpName(parsedCmd[2], &oper2);
			if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_4)
			{
				command = (int)OPCODE::divi_reg4_reg4;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_8)
			{
				command = (int)OPCODE::divi_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_4)
			{
				command = (int)OPCODE::divi_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::bit_8)
			{
				command = (int)OPCODE::divi_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_8)
			{
				command = (int)OPCODE::divi_reg8_val8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_16)
			{
				command = (int)OPCODE::divi_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_32)
			{
				command = (int)OPCODE::divi_reg8_val32;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_64)
			{
				command = (int)OPCODE::divi_reg8_val64;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else
			{
				printOpCodeError(*commandLine, "", (int)errList::InCorrectFormat);
				*commandLine = -1;
				*dest = "";
				return (op)errList::InCorrectFormat;
			}
		}
		else if (command == (int)prefOPCODE::modi && commandLength == 3)
		{
			checkResult1 = checkOpName(parsedCmd[1], &oper1);
			checkResult2 = checkOpName(parsedCmd[2], &oper2);
			if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_4)
			{
				command = (int)OPCODE::modi_reg4_reg4;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_8)
			{
				command = (int)OPCODE::modi_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_4)
			{
				command = (int)OPCODE::modi_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::bit_8)
			{
				command = (int)OPCODE::modi_reg8_reg8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_8)
			{
				command = (int)OPCODE::modi_reg8_val8;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_16)
			{
				command = (int)OPCODE::modi_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_32)
			{
				command = (int)OPCODE::modi_reg8_val32;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else if ((checkResult1 == (op)checkOp::bit_4 || checkResult1 == (op)checkOp::bit_8) && checkResult2 == (op)checkOp::val_64)
			{
				command = (int)OPCODE::modi_reg8_val64;
				writeBinaryData(dest, command, oper1, oper2);
				printBinaryData(command, oper1, oper2);
				return (op)errList::success;
			}
			else
			{
				printOpCodeError(*commandLine, "", (int)errList::InCorrectFormat);
				*commandLine = -1;
				*dest = "";
				return (op)errList::InCorrectFormat;
			}
		}
		else if (command == (int)prefOPCODE::jmp_eq && commandLength == 4)
		{
			checkResult1 = checkOpName(parsedCmd[1], &oper1);
			checkResult2 = checkOpName(parsedCmd[2], &oper2);
			checkResult3 = checkOpName(parsedCmd[3], &oper3);
			if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_4 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_eq_reg4_reg4_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_8 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_eq_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_4 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_eq_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_8 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_eq_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else
			{
				printOpCodeError(*commandLine, "", (int)errList::InCorrectFormat);
				*commandLine = -1;
				*dest = "";
				return (op)errList::InCorrectFormat;
			}
		}
		else if (command == (int)prefOPCODE::jmp_ne && commandLength == 4)
		{
			checkResult1 = checkOpName(parsedCmd[1], &oper1);
			checkResult2 = checkOpName(parsedCmd[2], &oper2);
			checkResult3 = checkOpName(parsedCmd[3], &oper3);
			if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_4 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_ne_reg4_reg4_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_8 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_ne_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_4 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_ne_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_8 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_ne_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else
			{
				printOpCodeError(*commandLine, "", (int)errList::InCorrectFormat);
				*commandLine = -1;
				*dest = "";
				return (op)errList::InCorrectFormat;
			}
		}
		else if (command == (int)prefOPCODE::jmp_gt && commandLength == 4)
		{
			checkResult1 = checkOpName(parsedCmd[1], &oper1);
			checkResult2 = checkOpName(parsedCmd[2], &oper2);
			checkResult3 = checkOpName(parsedCmd[3], &oper3);
			if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_4 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_gt_reg4_reg4_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_8 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_gt_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_4 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_gt_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_8 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_gt_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else
			{
				printOpCodeError(*commandLine, "", (int)errList::InCorrectFormat);
				*commandLine = -1;
				*dest = "";
				return (op)errList::InCorrectFormat;
			}
		}
		else if (command == (int)prefOPCODE::jmp_ge && commandLength == 4)
		{
			checkResult1 = checkOpName(parsedCmd[1], &oper1);
			checkResult2 = checkOpName(parsedCmd[2], &oper2);
			checkResult3 = checkOpName(parsedCmd[3], &oper3);
			if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_4 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_ge_reg4_reg4_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_8 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_ge_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_4 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_ge_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_8 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_ge_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else
			{
				printOpCodeError(*commandLine, "", (int)errList::InCorrectFormat);
				*commandLine = -1;
				*dest = "";
				return (op)errList::InCorrectFormat;
			}
		}
		else if (command == (int)prefOPCODE::jmp_lt && commandLength == 4)
		{
			checkResult1 = checkOpName(parsedCmd[1], &oper1);
			checkResult2 = checkOpName(parsedCmd[2], &oper2);
			checkResult3 = checkOpName(parsedCmd[3], &oper3);
			if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_4 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_lt_reg4_reg4_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_8 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_lt_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_4 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_lt_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_8 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_lt_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else
			{
				printOpCodeError(*commandLine, "", (int)errList::InCorrectFormat);
				*commandLine = -1;
				*dest = "";
				return (op)errList::InCorrectFormat;
			}
		}
		else if (command == (int)prefOPCODE::jmp_le && commandLength == 4)
		{
			checkResult1 = checkOpName(parsedCmd[1], &oper1);
			checkResult2 = checkOpName(parsedCmd[2], &oper2);
			checkResult3 = checkOpName(parsedCmd[3], &oper3);
			if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_4 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_le_reg4_reg4_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_4 && checkResult2 == (op)checkOp::bit_8 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_le_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_4 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_le_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else if (checkResult1 == (op)checkOp::bit_8 && checkResult2 == (op)checkOp::bit_8 &&
				(checkResult3 == (op)checkOp::val_16 || checkResult3 == (op)checkOp::val_8))
			{
				command = (int)OPCODE::jmp_le_reg8_reg8_val16;
				writeBinaryData(dest, command, oper1, oper2, oper3);
				printBinaryData(command, oper1, oper2, oper3);
				return (op)errList::success;
			}
			else
			{
				printOpCodeError(*commandLine, "", (int)errList::InCorrectFormat);
				*commandLine = -1;
				*dest = "";
				return (op)errList::InCorrectFormat;
			}
		}
		else if (command == (int)prefOPCODE::nop && commandLength == 1)
		{
			writeBinaryData(dest,command);
			printBinaryData(command);
		}
		else if (command == (int)prefOPCODE::halt && commandLength == 1)
		{
			writeBinaryData(dest, command);
			printBinaryData(command);
		}
		else
		{
			printOpCodeError(*commandLine, "", (int)errList::InCorrectFormat);
			*commandLine = -1;
			*dest = "";
			return (int)errList::InCorrectFormat;
		}
	}
	else
	{
		printOpCodeError(*commandLine, "", (int)errList::ContainSpace);
		*commandLine = -1;
		*dest = "";
		return (int)errList::ContainSpace;
	}
}

op checkOpName(string opName, op *opValue)
{
	if (opName.length() > 17) return (op)checkOp::error;
	string opHeader = opName.substr(0, 1);
	string opFooter = opName.substr(opName.length() - 1, opName.length());
	string opData = opName.substr(1, opName.length());
	string valData = opName.substr(0, opName.length() - 1);
	op data = 0;

	if (opHeader == "r")
	{
		try { data = std::stoll(opData); }
		catch (...) { return (op)checkOp::error; }
		
		*opValue = data;
		if (data <= 0x0f) return (op)checkOp::bit_4;
		else if (data <= 0xff) return (op)checkOp::bit_8;
		else return (op)checkOp::error;
	}
	else if (opFooter == "h")
	{
		try { data = std::stoull(valData,nullptr,16); }
		catch (...) { return (op)checkOp::error; }

		*opValue = data;
		if (data <= 0xff) return (op)checkOp::val_8;
		else if (data <= 0xffff) return (op)checkOp::val_16;
		else if (data <= 0xffffffff) return (op)checkOp::val_32;
		else if (data <= 0xffffffffffffffff) return (op)checkOp::val_64;
		else return (op)checkOp::error;
	}
	else
	{
		*opValue = 0;
		return (op)checkOp::error;
	}
}

void printBinaryData(op command, op oper1, op oper2)
{
	if (command == (int)OPCODE::mov_reg4_reg4 ||
		command == (int)OPCODE::addi_reg4_reg4)
	{
		op oper3 = (oper1 << 4) | oper2;
		std::cout << "0x" << std::setfill('0') << std::right << std::setw(2) << std::hex << command << " ";
		std::cout << "0x" << std::setfill('0') << std::right << std::setw(2) << std::hex << oper3 << endl;
	}
	else
	{
		std::cout << "0x" << std::setfill('0') << std::right << std::setw(2) << std::hex << command << " ";
		std::cout << "0x" << std::setfill('0') << std::right << std::setw(2) << std::hex << oper1 << " ";
		std::cout << "0x" << std::setfill('0') << std::right << std::setw(2) << std::hex << oper2 << endl;
	}
}
void printBinaryData(op command, op oper1, op oper2, op oper3)
{
	if (command == (int)OPCODE::jmp_eq_reg4_reg4_val16 ||
		command == (int)OPCODE::jmp_ne_reg4_reg4_val16)
	{
		std::cout << "0x" << std::setfill('0') << std::right << std::setw(2) << std::hex << command << " ";
		std::cout << "0x" << std::setfill('0') << std::right << std::setw(2) << std::hex << ((oper1 << 4) | oper2) << " ";
		std::cout << "0x" << std::setfill('0') << std::right << std::setw(2) << std::hex << oper3 << endl;
	}
	else
	{
		std::cout << "0x" << std::setfill('0') << std::right << std::setw(2) << std::hex << command << " ";
		std::cout << "0x" << std::setfill('0') << std::right << std::setw(2) << std::hex << oper1 << " ";
		std::cout << "0x" << std::setfill('0') << std::right << std::setw(2) << std::hex << oper2 << " ";
		std::cout << "0x" << std::setfill('0') << std::right << std::setw(2) << std::hex << oper3 << endl;
	}
}
void printBinaryData(op command)
{
	std::cout << "0x" << std::setfill('0') << std::right << std::setw(2) << std::hex << command << endl;
}
void writeBinaryData(string *dest, op command, op oper1, op oper2)
{
	// write
	if (command == (int)OPCODE::mov_reg4_reg4 || 
		command == (int)OPCODE::addi_reg4_reg4)
	{
		*dest += command;
		*dest += (oper1 << 4) | oper2;
	}
	else
	{		
		*dest += command;
		*dest += oper1;		
		dataSerializer(oper2, dest);
	}
}
void writeBinaryData(string *dest, op command, op oper1, op oper2, op oper3)
{
	if (command == (int)OPCODE::jmp_eq_reg4_reg4_val16 ||
		command == (int)OPCODE::jmp_ne_reg4_reg4_val16)
	{
		*dest += command;
		*dest += (oper1 << 4) | oper2;
		dataSerializer(oper3, dest);
	}
	else
	{
		*dest += command;
		*dest += oper1;
		*dest += oper2;
		dataSerializer(oper3, dest);
	}
}
void writeBinaryData(string *dest, op command)
{
	switch (command)
	{
		case (op)OPCODE::nop:
			*dest += command;
			break;
		case (op)OPCODE::halt:
			*dest += command;
			break;
	}	
}
void dataSerializer(op oper, string *dest)
{
	byte parseOp[8] = { 0, };
	parseOp[0] = oper >> (8 * 7);
	parseOp[1] = oper >> (8 * 6);
	parseOp[2] = oper >> (8 * 5);
	parseOp[3] = oper >> (8 * 4);
	parseOp[4] = oper >> (8 * 3);
	parseOp[5] = oper >> (8 * 2);
	parseOp[6] = oper >> (8 * 1);
	parseOp[7] = oper >> (8 * 0);
	byte checkPrev = 0;
	for (int i = 0; i < 8; i++)
	{
		if (parseOp[i])
		{
			*dest += (byte)parseOp[i];
			checkPrev = 1;
		}
		else
		{
			if (checkPrev == 1) *dest += (byte)parseOp[i];
		}
	}
	if (checkPrev == 0) *dest += oper;
}