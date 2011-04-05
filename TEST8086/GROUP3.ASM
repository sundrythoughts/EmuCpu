;
; GROUP3.ASM
; TESTS THE BASIC EXECUTION OF GROUP III INSTRUCTIONS
; BY Dan Wooster
;
         SETREG IP=MAIN
         SETREG SP=0100
         ORG 1000


; TEST SHIFT INSTRUCTIONS
;
;                            RESULT  OVER  SIGN  ZERO  AUX  CARRY
;                            ------  ----  ----  ----  ---  -----
MAIN:    MOV AX,FFFF
         MOV CL,5
         SHL AX,CL         ;   FFE0           -                 1
         MOV AX,FFFF
         SHR AX,CL         ;   07FF           +           1     1
         MOV AX,FFFF
         SAR AX,CL         ;   FFFF           -           1     1
         MOV CL,16
         MOV AX,FFFF
         SHL AX,CL         ;   0000
         MOV AX,FFFF
         SHR AX,CL         ;   0000
         MOV AX,FFFF
         SAR AX,CL         ;   FFFF

; TEST LOGICAL INSTRUCTIONS
;
;                            RESULT  OVER  SIGN  ZERO  AUX  CARRY
;                            ------  ----  ----  ----  ---  -----
         MOV AX,6666
         AND AX,1234       ;    0224    0     +     0    0      0
         MOV AX,6666
         OR  AX,1234       ;    7676
         MOV AX,6666
         XOR AX,1234       ;    7452
         MOV AX,6666
         TEST AX,1234      ;    6666
         MOV AX,6666
         NOT AX             ;   9999
         HLT

DATA1:   DW 6666
DATA2:   DB 33
