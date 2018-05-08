mov r10 ffh
nop
nop
nop
nop
subi r255 fa00h
jmp_eq r15 r14 ff0eh
mov r4 r5
addi r30 r10
addi r255 0h
addi r10 ff00ffh
muli r55 f0ffh
jmp_ne r255 r254 f023h
mov r10 7ch
mov r255 r254
jmp_lt r13 r9 bc74h
nop
nop
halt
nop
nop
divi r13 r21
jmp_le r13 r9 bc74h
modi r13 r23
jmp_ge r13 r9 bc74h
jmp_gt r13 r9 bc74h
mov r255 ff86fffbe7dcffcch
subi r254 ffh
addi r9 r12
addi r12 r13
jmp_ne r13 r9 bc74h
jmp_ne r4 r255 ff87h
mov r10 fah