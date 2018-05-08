## Assembler for FVM
It is being developed in line with FVM, and features will be added.<br>
Available commands: mov, addi, subi, jmp_eq, jmp_ne<br><br>

### 1. Command
```
Usage: asmFVM <command>

where <command> is onf of:
        --inl, --asm, --dsm

asmFVM <cmd> --inl                      in-line assemble mode
asmFVM <cmd> --asm <filename.asm>       file assemble mode
asmFVM <cmd> --dsm <filename.bin>       file disassemble mode
```

### 2. Success to assemble
```
>> Start assembling the data.asm file...

   Ln 01 : (mov r10 ffh                        ) - 0x12 0x0a 0xff
   Ln 02 : (subi r255 fa00h                    ) - 0x29 0xff 0xfa00
   Ln 03 : (jmp_eq r15 r14 ff0eh               ) - 0x80 0xfe 0xff0e
   Ln 04 : (mov r4 r5                          ) - 0x10 0x45
   Ln 05 : (addi r30 r10                       ) - 0x21 0x1e 0x0a
   Ln 06 : (addi r255 0h                       ) - 0x22 0xff 0x00
   Ln 07 : (addi r10 ff00ffh                   ) - 0x24 0x0a 0xff00ff
   Ln 08 : (jmp_ne r255 r254 f023h             ) - 0x83 0xff 0xfe 0xf023
   Ln 09 : (mov r10 7ch                        ) - 0x12 0x0a 0x7c
   Ln 0a : (mov r255 r254                      ) - 0x11 0xff 0xfe
   Ln 0b : (mov r255 ff86fffbe7dcffcch         ) - 0x15 0xff 0xff86fffbe7dcffcc
   Ln 0c : (subi r254 ffh                      ) - 0x28 0xfe 0xff
   Ln 0d : (addi r9 r12                        ) - 0x20 0x9c
   Ln 0e : (addi r12 r13                       ) - 0x20 0xcd
   Ln 0f : (jmp_ne r13 r9 bc74h                ) - 0x82 0xd9 0xbc74
   Ln 10 : (jmp_ne r4 r255 ff87h               ) - 0x83 0x04 0xff 0xff87
   Ln 11 : (mov r10 fah                        ) - 0x12 0x0a 0xfa

>> All lines have been successfully assembled.

--------------------------------------------------------

 *** Assemble Success

  Output File Name : data.bin

--------------------------------------------------------
```

### 3. Fail to assemble
```
>> Start assembling the data.asm file...

   Ln 01 : (mov r10 ffh                        ) - 0x12 0x0a 0xff
   Ln 02 : (subi r255 fa00h                    ) - 0x29 0xff 0xfa00
   Ln 03 : (jmp_eq r15 r14 ff0eh               ) - 0x80 0xfe 0xff0e
   Ln 04 : (mov r4 r5                          ) - 0x10 0x45
   Ln 05 : (addi r30 r10                       ) - 0x21 0x1e 0x0a
   Ln 06 : (addi r255 0h                       ) - 0x22 0xff 0x00
   Ln 07 : (addi r10 ff00ffh                   ) - 0x24 0x0a 0xff00ff
   Ln 08 : (jmsp_ne r255 r254 f023h            ) - ERROR

--------------------------------------------------------

 *** Assemble Error

  Ln 08 : JMSP_NE command is not recognized.

--------------------------------------------------------

>> Bin file creation failed due to an error.

Press any key to continue . . .
```

