; SOURCE: test7.asm
; OBJECT FILE : TEST1.OBJ
; AUTHOR      : PHIL HAENES
; DESCRIPTION : A NUMBER IS ENTERED, AND ALL NUMBERS FROM 1 TO N ARE ADDED,
;               AND THE ANSWER IS OUTPUT
; TESTS THE FOLLOWING INSTRUCTIONS: LEA, MOV IMMEDIATE TO REGISTER, MOV
;                                   REGISTER TO REGISTER, ADD REGISTER TO
;                                   REGISTER, INC REGISTER, LOOP, POP REGISTER,
;                                   PUSH REGISTER, HLT, INT (AND ALL
;                                   INSTRUCTIONS USED BY THE INTERRUPTS CALLED)
; INTERRUPTS CALLED : 10,11,12,13

SETREG IP = BEGIN
SETREG SP = 5FFF
SETREG FL = FEFF
CR EQU %13
LF EQU %10
ORG 1000
PROMPT: DB "Enter a number to be summed $"
LINE1: DB CR,LF,CR,LF,"The sum of all numbers from 1 to "
ENTRY: DB "      "
LINE2: DB CR,LF,"is equal to "
ANSWER: DB "     $"
NUMIN: DB BLOCK 50 {0}
BEGIN: LEA  DX,PROMPT
       INT  10
       MOV  CX,50
       LEA  DX,NUMIN
       INT  11
       LEA  DX,NUMIN
       INT  12
       PUSH AX
       MOV  CX,AX
       MOV  BX,1
       MOV  AX,0
ADDNUM:
       ADD  AX,BX
       INC  BX
       LOOP ADDNUM
       LEA  DX,ANSWER
       INT  13
       POP  AX
       LEA  DX,ENTRY
       INT  13
       LEA  DX,LINE1
       INT  10
       HLT