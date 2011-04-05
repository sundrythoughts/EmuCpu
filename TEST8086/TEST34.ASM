;
; GR2.ASM
; TESTS GROUP II INSTRUCTIONS
; BY DONALD R. CONGDON 1990
;
         SETREG IP=MAIN
         SETREG SP=0100
         ORG 1000
MAIN:    LEA DX,MSG1
         INT 10
         LEA DX,MSG2
         INT 10
         LEA DX,MSG3
         INT 10
         MOV AX,0000
         MOV BX,0000
SCAN:    IN AL,01
         CMP AL,'Q'         ; CHECK FOR QUIT
         JE END1
         SUB AL,30          ; CONVERT SINGLE ASCII TO HEX
         ADD BX,AX          ; ADDS NEW NUMBER TO SUM
         JMP SCAN
END1:    LEA DX,MSG4
         INT 10
         HLT
MSG1:    DW "ADDER: ADDS SINGLE DIGITS",A,D,"$"
MSG2:    DW "ENTER SINGLE DIGIT NUMBERS",A,D,"$"
MSG3:    DW "ENTER A 'Q' TO END",A,D,"$"
MSG4:    DW A,D,"PROGRAM COMPLETE",A,D,"$"
         ORG 5000
         DW
