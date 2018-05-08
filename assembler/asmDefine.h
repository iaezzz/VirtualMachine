//
//  asmDefine.h
//  asmFVM
//
//  Created by Yousung Cha on 5/8/18.
//  Copyright © 2018 Fantom Foundation. All rights reserved.
//

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm> 
#include <iomanip>

using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::ifstream;
using std::vector;
using std::istream_iterator;
using std::istringstream;
using std::transform;

using op = unsigned long long;
using byte = unsigned char;

enum class sysCommand
{
	NoCommand = 1,
	InLineMode = 2,
	OtherMode = 3,
};
enum class regSet_4bit
{
	r0 = 0x00, r1 = 0x01, r2 = 0x02, r3 = 0x03, r4 = 0x04, r5 = 0x05, r6 = 0x06, r7 = 0x07,
	r8 = 0x08, r9 = 0x09, r10 = 0x0a, r11 = 0x0b, r12 = 0x0c, r13 = 0x0d, r14 = 0x0e, r15 = 0x0f,
};
enum class regSet_8bit
{
	r16 = 0x10, r17 = 0x11, r18 = 0x12, r19 = 0x13, r20 = 0x14, r21 = 0x15, r22 = 0x16, r23 = 0x17, 
	r24 = 0x18, r25 = 0x19, r26 = 0x1a, r27 = 0x1b, r28 = 0x1c, r29 = 0x1d, r30 = 0x1e, r31 = 0x1f, 
	r32 = 0x20, r33 = 0x21, r34 = 0x22, r35 = 0x23, r36 = 0x24, r37 = 0x25, r38 = 0x26, r39 = 0x27,
	r40 = 0x28, r41 = 0x29, r42 = 0x2a, r43 = 0x2b, r44 = 0x2c, r45 = 0x2d, r46 = 0x2e, r47 = 0x2f,
};
enum class checkOp
{
	bit_4 = 0x04, bit_8 = 0x08,
	val_8 = 0xf0, val_16 = 0xf1, val_32 = 0xf2, val_64 = 0xf3,
	error = 0x00,
};
enum class errList
{
	NoCommand = 0x00,
	NoFileName = 0x01,
	NoFile = 0x02,
	NoOpCommand = 0x03,
	InCorrectFormat = 0x04,
	ContainSpace = 0x05,
	ParseFail = 0x06,
	success = 0xff,
};
enum class prefOPCODE
{
	mov = 0x01,
	addi = 0x02,
	addf = 0x03,
	subi = 0x04,
	subf = 0x05,
	muli = 0x06,
	mulf = 0x07,
	modi = 0x08,
	modf = 0x09,
	divi = 0x0a,
	divf = 0x0b,
	jmp_eq = 0x0c,
	jmp_ne = 0x0d,
	jmp_gt = 0x0e,
	jmp_ge = 0x0f,
	jmp_lt = 0x10,
	jmp_le = 0x11,
	halt = 0x0f,
	nop = 0x00,
};
enum class OPCODE
{
	mov_reg4_reg4 = 0x10,
	mov_reg8_reg8 = 0x11,
	mov_reg8_val8 = 0x12,
	mov_reg8_val16 = 0x13,
	mov_reg8_val32 = 0x14,
	mov_reg8_val64 = 0x15,

	addi_reg4_reg4 = 0x20,
	addi_reg8_reg8 = 0x21,
	addi_reg8_val8 = 0x22,
	addi_reg8_val16 = 0x23,
	addi_reg8_val32 = 0x24,
	addi_reg8_val64 = 0x25,
	
	subi_reg4_reg4 = 0x26,
	subi_reg8_reg8 = 0x27,
	subi_reg8_val8 = 0x28,
	subi_reg8_val16 = 0x29,
	subi_reg8_val32 = 0x3a,
	subi_reg8_val64 = 0x3b,

	muli_reg4_reg4 = 0x40,
	muli_reg8_reg8 = 0x41,
	muli_reg8_val8 = 0x42,
	muli_reg8_val16 = 0x43,
	muli_reg8_val32 = 0x44,
	muli_reg8_val64 = 0x45,

	divi_reg4_reg4 = 0x46,
	divi_reg8_reg8 = 0x47,
	divi_reg8_val8 = 0x48,
	divi_reg8_val16 = 0x49,
	divi_reg8_val32 = 0x4a,
	divi_reg8_val64 = 0x4b,

	modi_reg4_reg4 = 0x4c,
	modi_reg8_reg8 = 0x4d,
	modi_reg8_val8 = 0x4e,
	modi_reg8_val16 = 0x4f,
	modi_reg8_val32 = 0x50,
	modi_reg8_val64 = 0x51,
	
	addf_reg4_reg4 = 0x60,
	addf_reg8_reg8 = 0x61,
	addf_reg8_val64 = 0x62,

	subf_reg4_reg4 = 0x63,
	subf_reg8_reg8 = 0x64,
	subf_reg8_val64 = 0x65,

	mulf_reg4_reg4 = 0x66,
	mulf_reg8_reg8 = 0x67,
	mulf_reg8_val64 = 0x68,

	divf_reg4_reg4 = 0x69,
	divf_reg8_reg8 = 0x6a,
	divf_reg8_val64 = 0x6b,

	jmp_eq_reg4_reg4_val16 = 0x80,
	jmp_eq_reg8_reg8_val16 = 0x81,
	jmp_ne_reg4_reg4_val16 = 0x82,
	jmp_ne_reg8_reg8_val16 = 0x83,
	jmp_gt_reg4_reg4_val16 = 0x84,
	jmp_gt_reg8_reg8_val16 = 0x85,
	jmp_ge_reg4_reg4_val16 = 0x86,
	jmp_ge_reg8_reg8_val16 = 0x87,
	jmp_lt_reg4_reg4_val16 = 0x88,
	jmp_lt_reg8_reg8_val16 = 0x89,
	jmp_le_reg4_reg4_val16 = 0x8a,
	jmp_le_reg8_reg8_val16 = 0x8b,

	jmp_eq_reg4_reg4_val32 = 0x8c,
	jmp_eq_reg8_reg8_val32 = 0x8d,
	jmp_ne_reg4_reg4_val32 = 0x8e,
	jmp_ne_reg8_reg8_val32 = 0x8f,
	jmp_gt_reg4_reg4_val32 = 0x90,
	jmp_gt_reg8_reg8_val32 = 0x91,
	jmp_ge_reg4_reg4_val32 = 0x92,
	jmp_ge_reg8_reg8_val32 = 0x93,
	jmp_lt_reg4_reg4_val32 = 0x94,
	jmp_lt_reg8_reg8_val32 = 0x95,
	jmp_le_reg4_reg4_val32 = 0x96,
	jmp_le_reg8_reg8_val32 = 0x97,

	new_val8_val8_val8 = 0xa0, 
	new_val16_val8_val8 = 0xa1,

	call_static_val8_val8_val8 = 0xa3,
	call_dynamic_ref8_val8_val8_val8 = 0xa4,

	load_reg8_ref8_val8 = 0xa5,
	load_reg8_ref8_val16 = 0xa6,
	store_reg8_ref8_val8 = 0xa7,
	store_reg8_ref8_val16 = 0xa8,

	ret_reg8 = 0xaa,
	ret_val8 = 0xab,
	ret_val16 = 0xac,
	ret_val32 = 0xad,
	ret_val64 = 0xae,

	movret_reg8 = 0xaf,

	halt = 0x0f,
	nop = 0x00,
};