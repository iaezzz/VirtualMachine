//
//  opcode.h
//  fvm
//
//  Created by Fantom Foundation
//  Copyright © 2018 Fantom Foundation. All rights reserved.
//

#ifndef opcode_h
#define opcode_h

#include <boost/preprocessor.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/array/insert.hpp>

#define DECL_REG(z, n, t) r ## n = n

enum class REGISTERS {
    BOOST_PP_ENUM(256, DECL_REG, int)
};

// Todo: We will use preprocessors more agresstively.

#define DEFINE_OPCODE_TO_STRING(r, data, elem)                                \
    case elem : return BOOST_PP_STRINGIZE(elem);

#define DEFINE_OPCODES(name, enumerators)                                     \
    enum class name {                                                         \
        BOOST_PP_SEQ_ENUM(enumerators)                                        \
        };                                                                    \
    inline const char* ToString(name v)                                       \
    {                                                                         \
        switch (v)                                                            \
        {                                                                     \
            BOOST_PP_SEQ_FOR_EACH(                                            \
                DEFINE_OPCODE_TO_STRING,                                      \
                name,                                                         \
                enumerators                                                   \
            )                                                                 \
            default: return "[Unknown OpCode: " BOOST_PP_STRINGIZE(name) "]"; \
        }                                                                     \
    }

enum class OPERAND_TYPE
{
    none = 0,
    reg_4 = 1,
    reg_8 = 2,
    reg_16 = 3,
    reg_32 = 4,
    val_8 = 5,
    val_16 = 6,
    val_32 = 7,
    val_64 = 8,
    ref_reg_4 = 9,
    ref_reg_8 = 10,
    ref_reg_6 = 11,
    ref_reg_32 = 12,
    ref_reg_64 = 13,
    ref_val_8 = 14,
    ref_val_16 = 15,
    ref_val_32 = 16,
    ref_val_64 = 17,
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

    new_val8_val8_val8 = 0xa0, // Target, ConstuctorIndex, RegStart, RegNum
    new_val16_val8_val8 = 0xa1, //
    
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

inline int getOpLen(OPERAND_TYPE op)
{
    switch(op)
    {
        case OPERAND_TYPE::none:
            return 0;
        case OPERAND_TYPE::reg_4:
            return 1;
        case OPERAND_TYPE::reg_8:
            return 1;
        case OPERAND_TYPE::reg_16:
            return 2;
        case OPERAND_TYPE::reg_32:
            return 4;
        case OPERAND_TYPE::val_8:
            return 1;
        case OPERAND_TYPE::val_16:
            return 2;
        case OPERAND_TYPE::val_32:
            return 4;
        case OPERAND_TYPE::val_64:
            return 8;
        default:
            return 0; //undefined behavior
    }
};

class OperandStruct
{
public:
    int oplen[3] = {0};
    int totalLength = 0;
    
    OPERAND_TYPE optype[3] = {OPERAND_TYPE::none};

    OperandStruct()
    {
    }

    OperandStruct(OPERAND_TYPE op1, OPERAND_TYPE op2, OPERAND_TYPE op3 = OPERAND_TYPE::none)
    {
        oplen[0] = getOpLen(op1);
        oplen[1] = getOpLen(op2);
        oplen[2] = getOpLen(op3);
        optype[0] = op1;
        optype[1] = op2;
        optype[2] = op3;

        if(op1 == OPERAND_TYPE::ref_reg_4 && op1 == OPERAND_TYPE::reg_4)
        {
            totalLength = 1 + oplen[2];
        } else
        {
            totalLength = oplen[0] + oplen[1];
            if(op2 != OPERAND_TYPE::reg_4 && op2 != OPERAND_TYPE::ref_reg_4)
            {
                totalLength += oplen[2];;
            }
        }
    }
};

class OpcodeUtil
{
public:
    static OperandStruct aOpcode[256];

    static OpcodeUtil& GetInstance() {
        static OpcodeUtil myInstance;
        return myInstance;
    }

    OpcodeUtil(OpcodeUtil const&) = delete;
    OpcodeUtil(OpcodeUtil&&) = delete;
    OpcodeUtil& operator=(OpcodeUtil const&) = delete;
    OpcodeUtil& operator=(OpcodeUtil &&) = delete;
    
protected:
    OpcodeUtil();

    ~OpcodeUtil() {
    }
};

//Initialize_
#endif /* opcode_h */

