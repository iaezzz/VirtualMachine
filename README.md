## **Fantom Virtual Machine**
FVM is a register-based, object-oriented virtual machine that also supports floating-point operation for Fantom project.

## **FVM Instruction List**
There are features that have not been added yet, and we plan to create and update them.

### *1. MOV*
> ex) mov r0 r15<br>
> ex) mov r15 fe37h

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **mov**       | 4bit Register  | 4bit Register | -             | -                             | **v**          |
| **mov**       | 8bit Register  | 8bit Register | -             | -            		  	     | **v**          |
| **mov**       | 8bit Register  | 8bit Value    | -             | -             		         | **v**          |
| **mov**       | 8bit Register  | 16bit Value   | -             | -            		  	     | **v**          |
| **mov**       | 8bit Register  | 32bit Value   | -             | -             		         | **v**          |
| **mov**       | 8bit Register  | 64bit Value   | -             | -             		         | **v**          |
| **mov**       | 8bit Ref-Reg.  | Registers     | -             | -                             | -              |
| **mov**       | 8bit Ref-Reg.  | 64bit Value   | -             | -                             | -              |
| **mov**       | 64bit Ref-Val. | Registers     | -             | -        			         | -              |
| **mov**       | 8bit Register  | Ref-Vals      | -             | -       			             | -              |
| **mov-obj**   | 8bit Register  | 8bit Register | -             | -            			     | -              |
| **load-obj**  | 8bit Register  | 8bit Register | -             | *Load obj from obj repo*      | -              |
| **store-obj** | 8bit Register  | 8bit Register | -             | *store obj from obj repo*     | -              |
<br>

### *2. ADDI*
> ex) addi r28 r78  
> ex) addi r30 ffffh    

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **addi**      | 4bit Register  | 4bit Register | -             | -                             | **v**          |
| **addi**      | 8bit Register  | 8bit Register | -             | -            		  	     | **v**          |
| **addi**      | 8bit Register  | 8bit Value    | -             | -             		         | -              |
| **addi**      | 8bit Register  | 16bit Value   | -             | -            		  	     | -              |
| **addi**      | 8bit Register  | 32bit Value   | -             | -             		         | -              |
| **addi**      | 8bit Register  | 64bit Value   | -             | -             		         | -              |
<br>

### *3. ADDF*
> ex) addf r28 r78  
> ex) addf r30 ffffh    

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **addf**      | 4bit Register  | 4bit Register | -             | -                             | **v**          |
| **addf**      | 8bit Register  | 8bit Register | -             | -            		  	     | **v**          |
| **addf**      | 8bit Register  | 8bit Value    | -             | -             		         | -              |
| **addf**      | 8bit Register  | 16bit Value   | -             | -            		  	     | -              |
| **addf**      | 8bit Register  | 32bit Value   | -             | -             		         | -              |
| **addf**      | 8bit Register  | 64bit Value   | -             | -             		         | -              |
<br>

### *4. SUBI*
> ex) subi r2 r7  
> ex) subi r3 57h    

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **subi**      | 4bit Register  | 4bit Register | -             | -                             | **v**          |
| **subi**      | 8bit Register  | 8bit Register | -             | -            		  	     | **v**          |
| **subi**      | 8bit Register  | 8bit Value    | -             | -             		         | -              |
| **subi**      | 8bit Register  | 16bit Value   | -             | -            		  	     | -              |
| **subi**      | 8bit Register  | 32bit Value   | -             | -             		         | -              |
| **subi**      | 8bit Register  | 64bit Value   | -             | -             		         | -              |
<br>

### *5. SUBF*
> ex) subf r2 r7  
> ex) subf r3 57h    

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **subf**      | 4bit Register  | 4bit Register | -             | -                             | **v**          |
| **subf**      | 8bit Register  | 8bit Register | -             | -            		  	     | **v**          |
| **subf**      | 8bit Register  | 8bit Value    | -             | -             		         | -              |
| **subf**      | 8bit Register  | 16bit Value   | -             | -            		  	     | -              |
| **subf**      | 8bit Register  | 32bit Value   | -             | -             		         | -              |
| **subf**      | 8bit Register  | 64bit Value   | -             | -             		         | -              |
<br>

### *6. MULI*
> ex) muli r2 r7

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **muli**      | 4bit Register  | 4bit Register | -             | -                             | **v**          |
| **muli**      | 8bit Register  | 8bit Register | -             | -            		  	     | **v**          |
| **muli**      | 8bit Register  | 8bit Value    | -             | -             		         | -              |
| **muli**      | 8bit Register  | 16bit Value   | -             | -            		  	     | -              |
| **muli**      | 8bit Register  | 32bit Value   | -             | -             		         | -              |
| **muli**      | 8bit Register  | 64bit Value   | -             | -             		         | -              |
<br>

### *7. MULF*
> ex) mulf r22 r17

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **mulf**      | 4bit Register  | 4bit Register | -             | -                             | **v**          |
| **mulf**      | 8bit Register  | 8bit Register | -             | -            		  	     | **v**          |
| **mulf**      | 8bit Register  | 8bit Value    | -             | -             		         | -              |
| **mulf**      | 8bit Register  | 16bit Value   | -             | -            		  	     | -              |
| **mulf**      | 8bit Register  | 32bit Value   | -             | -             		         | -              |
| **mulf**      | 8bit Register  | 64bit Value   | -             | -             		         | -              |
<br>

### *8. DIVI*
> ex) divi r22 r17

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **divi**      | 4bit Register  | 4bit Register | -             | -                             | **v**          |
| **divi**      | 8bit Register  | 8bit Register | -             | -            		  	     | **v**          |
| **divi**      | 8bit Register  | 8bit Value    | -             | -             		         | -              |
| **divi**      | 8bit Register  | 16bit Value   | -             | -            		  	     | -              |
| **divi**      | 8bit Register  | 32bit Value   | -             | -             		         | -              |
| **divi**      | 8bit Register  | 64bit Value   | -             | -             		         | -              |
<br>

### *8. DIVF*
> ex) divf r22 r17

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **divf**      | 4bit Register  | 4bit Register | -             | -                             | **v**          |
| **divf**      | 8bit Register  | 8bit Register | -             | -            		  	     | **v**          |
| **divf**      | 8bit Register  | 8bit Value    | -             | -             		         | -              |
| **divf**      | 8bit Register  | 16bit Value   | -             | -            		  	     | -              |
| **divf**      | 8bit Register  | 32bit Value   | -             | -             		         | -              |
| **divf**      | 8bit Register  | 64bit Value   | -             | -             		         | -              |
<br>


### *9. JMP_EQ*
> ex) jmp_eq r22 r17 1023h

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **jmp_eq**    | 4bit Register  | 4bit Register | 16bit Value   | -                             | **v**          |
| **jmp_eq**    | 8bit Register  | 8bit Register | 16bit Value   | -            		  	     | **v**          |
| **jmp_eq**    | 4bit Register  | 4bit Register | 32bit Value   | -                             | **v**          |
| **jmp_eq**    | 8bit Register  | 8bit Register | 32bit Value   | -            		  	     | **v**          |
<br>

### *10. JMP_NE*
> ex) jmp_ne r2 r17 fe37h

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **jmp_ne**    | 4bit Register  | 4bit Register | 16bit Value   | -                             | **v**          |
| **jmp_ne**    | 8bit Register  | 8bit Register | 16bit Value   | -            		  	     | **v**          |
| **jmp_ne**    | 4bit Register  | 4bit Register | 32bit Value   | -                             | **v**          |
| **jmp_ne**    | 8bit Register  | 8bit Register | 32bit Value   | -            		  	     | **v**          |
<br>

### *11. JMP_GT*
> ex) jmp_gt r22 r19 fe370f21h

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **jmp_gt**    | 4bit Register  | 4bit Register | 16bit Value   | -                             | **v**          |
| **jmp_gt**    | 8bit Register  | 8bit Register | 16bit Value   | -            		  	     | **v**          |
| **jmp_gt**    | 4bit Register  | 4bit Register | 32bit Value   | -                             | **v**          |
| **jmp_gt**    | 8bit Register  | 8bit Register | 32bit Value   | -            		  	     | **v**          |
<br>

### *12. JMP_GE*
> ex) jmp_ge r22 r19 fe370f21h

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **jmp_ge**    | 4bit Register  | 4bit Register | 16bit Value   | -                             | **v**          |
| **jmp_ge**    | 8bit Register  | 8bit Register | 16bit Value   | -            		  	     | **v**          |
| **jmp_ge**    | 4bit Register  | 4bit Register | 32bit Value   | -                             | **v**          |
| **jmp_ge**    | 8bit Register  | 8bit Register | 32bit Value   | -            		  	     | **v**          |
<br>

### *13. JMP_LT*
> ex) jmp_lt r22 r19 fe370f21h

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **jmp_lt**    | 4bit Register  | 4bit Register | 16bit Value   | -                             | **v**          |
| **jmp_lt**    | 8bit Register  | 8bit Register | 16bit Value   | -            		  	     | **v**          |
| **jmp_lt**    | 4bit Register  | 4bit Register | 32bit Value   | -                             | **v**          |
| **jmp_lt**    | 8bit Register  | 8bit Register | 32bit Value   | -            		  	     | **v**          |
<br>

### *14. JMP_LE*
> ex) jmp_le r22 r19 fe370f21h

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **jmp_le**    | 4bit Register  | 4bit Register | 16bit Value   | -                             | **v**          |
| **jmp_le**    | 8bit Register  | 8bit Register | 16bit Value   | -            		  	     | **v**          |
| **jmp_le**    | 4bit Register  | 4bit Register | 32bit Value   | -                             | **v**          |
| **jmp_le**    | 8bit Register  | 8bit Register | 32bit Value   | -            		  	     | **v**          |
<br>

### *15. NEW - Create new instance of object*
> ex) new ffh 37h e7h  
> ex) new c736h 37h e7h  

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **new**       | 8bit Value     | 8bit Value    | 8bit Value    | -                             | -              |
| **new**       | 16bit Value    | 8bit Value    | 8bit Value    | -                             | -              |
<br>

### *16. CALL - Call a method of object*
> ex) call_static ffh 37h e7h  
> ex) call_dynamic c7h 15h f0h  

| **Command**      | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|------------------|----------------|---------------|---------------|-------------------------------|----------------|
| **call_static**  | 8bit Value     | 8bit Value    | 8bit Value    | -                             | -              |
| **call_dynamic** | 8bit Value     | 8bit Value    | 8bit Value    | -                             | -              |
<br>

### *17. LOAD  - Get a value of the instance*
> ex) load r32 r27 ffh
> ex) load r15 r7 7c3fh

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **load**      | 8bit Register  | 8bit Register | 8bit Value    | -                             | -              |
| **load**      | 8bit Register  | 8bit Register | 16bit Value   | -                             | -              |
<br>

### *18. STORE   - Set a value of a instance*
> ex) store r32 r27 ffh
> ex) store r15 r7 7c3fh

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **store**     | 8bit Register  | 8bit Register | 8bit Value    | -                             | -              |
| **store**     | 8bit Register  | 8bit Register | 16bit Value   | -                             | -              |
<br>

### *19. RET*
> ex) ret r35
> ex) ret r4
> ex) ret 37h
> ex) ret 371f2c39h

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **ret**       | 8bit Register  | -             | -             | -                             | -              |
| **ret**       | 8bit Value     | -             | -             | -                             | -              |
| **ret**       | 16bit Value    | -             | -             | -                             | -              |
| **ret**       | 32bit Value    | -             | -             | -                             | -              |
| **ret**       | 64bit Value    | -             | -             | -                             | -              |
<br>

### *20. MOVRET*
> ex) movret r35

| **Command**   | Operand 1      | Operand 2     | Operand 3     | Description      	 	     | Implementation |
|---------------|----------------|---------------|---------------|-------------------------------|----------------|
| **movret**    | 8bit Register  | -             | -             | -                             | -              |
<br>
