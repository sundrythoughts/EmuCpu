; SOURCE FILE : TEST11.ASM
; OBJECT FILE : TEST4.OBJ
; AUTHOR      : PHIL HAENES
; DESCRIPTION : 8 NUMBERS ARE ENTERED AND GROUPED INTO FOUR PAIRS, EACH OF
;               WHICH BECOMES THE SCORE TO ONE OF FOUR BOWL GAMES, AND THE SAME
;               TEAMS WIN EACH TIME THE PROGRAM IS RUN, NO MATTER WHAT ORDER
;               THE NUMBERS ARE ENTERED
; TESTS THE FOLLOWING INSTRUCTIONS : LEA, MOV IMMEDIATE TO REGISTER, CALL INTRA
;                                    SEGMENT, PUSH REGISTER, MOV REGISTER TO
;                                    REGISTER, POP REGISTER, ADD REGISTER TO
;                                    REGISTER, SUBTRACT REGISTER FROM REGISTER,
;                                    JA, HLT, INT (AND ALL INSTRUCTIONS USED IN
;                                    THE INTERRUPTS CALLED)
; INTERRUPTS CALLED : 10,11,12,13

SETREG IP = BEGIN
SETREG SP = 5FFF
SETREG FL = FEFF
CR EQU %13
LF EQU %10
ORG 1000
PROMPT : DB "Enter 8 numbers, each separated by a space $"
INPUT: DB BLOCK 50 {0}
MESS1: DB CR,LF,CR,LF,"Rose Bowl   :   Michigan    "
OUT1 : DB "          "
MESS2 : DB "Southern Cal   "
OUT2 : DB "          "
MESS3 : DB CR,LF,"Orange Bowl :   Nebraska    "
OUT3 : DB "          "
MESS4 : DB "Miami          "
OUT4 : DB "          "
MESS5 : DB CR,LF,"Citrus Bowl :   Clemson     "
OUT5 : DB "          "
MESS6 : DB "Oklahoma       "
OUT6 : DB "          "
MESS7 : DB CR,LF,"Fiesta Bowl :   Notre Dame  "
OUT7 : DB "          "
MESS8 : DB "West Virginia  "
OUT8 : DB "          $"
BEGIN: LEA  DX,PROMPT
       INT  10
       MOV  CX,50
       LEA  DX,INPUT
       INT  11
       MOV  CX,0
       MOV  BP,0
       CALL GETSCORE
       PUSH CX
       LEA  DX,OUT1
       INT  13
       MOV  AX,SI
       LEA  DX,OUT2
       INT  13
       POP  CX
       CALL GETSCORE
       PUSH CX
       LEA  DX,OUT3
       INT  13
       MOV  AX,SI
       LEA  DX,OUT4
       INT  13
       POP  CX
       CALL GETSCORE
       PUSH CX
       LEA  DX,OUT5
       INT  13
       MOV  AX,SI
       LEA  DX,OUT6
       INT  13
       POP  CX
       CALL GETSCORE
       PUSH CX
       LEA  DX,OUT7
       INT  13
       MOV  AX,SI
       LEA  DX,OUT8
       INT  13
       LEA  DX,MESS1
       INT  10
       HLT
GETSCORE:
       ADD  BP,CX
       LEA  DX,[INPUT + BP]
       INT  12
       PUSH AX
       ADD  BP,CX
       LEA  DX,[INPUT + BP]
       INT  12
       MOV  BX,AX
       POP  SI
       SUB  BX,SI
       JA   BIGGER
       MOV  DI,SI
       MOV  SI,AX
       MOV  AX,DI
BIGGER:
       RET