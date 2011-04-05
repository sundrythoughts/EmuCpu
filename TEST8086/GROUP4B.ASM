;
; GROUP4.ASM
; TESTS GROUP IV INSTRUCTIONS
; BY DONALD R. CONGDON 1990
;
         SETREG IP=MAIN
         SETREG SP=0100
         ORG 1000
MAIN:    MOV AX,0
         CALL SUB1
         JMP SUB2
RETN:    MOV AX,%10
         LEA DX,MSG1
LOOP1:   INT 10
         DEC AX
         CMP AX,0
         JZ DONE1
         JMP LOOP1
DONE1:   LEA DX,MSG2
         INT 10
         STC
         JC LOOP2
         LEA DX,MSG3
         INT 10
         JMP END
LOOP2:   LEA DX,MSG4
         INT 10
END:     LEA DX,MSG7
         INT 10
         HLT
;
; SUBROUTINE TEST
;
SUB1:    LEA DX,MSG5
         INT 10
         RET
;
; JUMP TEST
;
SUB2:    LEA DX,MSG6
         INT 10
         JMP RETN
TERMIN:  DB 0
MSG1:    DW "HELLO",D,A,"$"
MSG2:    DW "DONE WITH LOOP",D,A,"$"
MSG3:    DW "FAILURE",D,A,"$"
MSG4:    DW "SUCCESS",D,A,"$"
MSG5:    DW "SUBROUTINE RUNNING",D,A,"$"
MSG6:    DW "JUMP WORKED",D,A,"$"
MSG7:    DW "DONE WITH TESTS",D,A,"$"
