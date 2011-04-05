; SOURCE: test8.asm
; OBJECT FILE : TEST2.OBJ
; AUTHOR      : PHIL HAENES
; DESCRIPTION : FIVE NUMBERS ARE ENTERED, AND ALL FIVE NUMBERS ARE ADDED AND
;               AVERAGED, AND THE HIGHEST AND LOWEST NUMBER IS DETECTED, ALL
;               OF WHICH IS OUTPUT
; USES THE FOLLOWING INSTRUCTIONS : LEA, MOV IMMEDIATE TO REGISTER, PUSH
;                                   REGISTER, ADD REGISTER TO REGISTER, CMP
;                                   REGISTER TO REGISTER, JGE, POP REGISTER,
;                                   JLE, DEC, JNZ, DIV, HLT, INT (AND ALL
;                                   INSTRUCTIONS USED BY THE INTERRUPTS CALLED)
; INTERRUPTS CALLED : 10,11,12,13

SETREG IP = BEGIN
SETREG SP = 5FFF
SETREG FL = FEFF
CR EQU %13
LF EQU %10
ORG 1000
PROMPT: DB "Enter 5 numbers, each separated by a space $"
MESS1: DB CR,LF,CR,LF,"The sum of the numbers is "
SUM: DB "     $"
MESS2: DB CR,LF,"The average of the numbers is "
AVG: DB "     $"
MESS3: DB CR,LF,"The highest of the numbers is "
HIGH: DB "     $"
MESS4: DB CR,LF,"The lowest of the numbers is "
LOW: DB "     $"
ENTRY: DB BLOCK 50 {0}
BEGIN: LEA  DX,PROMPT
       INT  10
       MOV  CX,50
       LEA  DX,ENTRY
       INT  11
       MOV  DI,7FFF
       PUSH DI
       MOV  AX,0
       MOV  BX,0
       MOV  CX,0
       MOV  SI,5
       MOV  BP,0
       MOV  DI,0
ADDNUM:
       ADD  BP,CX
       LEA  DX,[ENTRY + BP]
       INT  12
       ADD  BX,AX
       CMP  DI,AX
       JGE  SMALLER
       MOV  DI,AX
SMALLER:
       POP  DX
       CMP  DX,AX
       JLE  BIGGER
       MOV  DX,AX
BIGGER:
       PUSH DX
       DEC  SI
       JNZ  ADDNUM
       MOV  AX,BX
       LEA  DX,SUM
       INT  13
       MOV  DX,0
       MOV  BP,5
       DIV  BP
       LEA  DX,AVG
       INT  13
       MOV  AX,DI
       LEA  DX,HIGH
       INT  13
       POP  AX
       LEA  DX,LOW
       INT  13
       LEA  DX,MESS1
       INT  10
       LEA  DX,MESS2
       INT  10
       LEA  DX,MESS3
       INT  10
       LEA  DX,MESS4
       INT  10
       HLT