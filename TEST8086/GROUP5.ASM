;
; GROUP5.ASM
; TESTS FLAG RELATED GROUP V INSTRUCTIONS
; BY DONALD R. CONGDON 1990
;
         SETREG IP=MAIN
         SETREG SP=0100
         ORG 1000
MAIN:    LEA DX,MSG1
         INT 10
         MOV AX,0A
LOOP1:   STC
         CALL DELAY
         CLC
         STI
         CALL DELAY
         CLI
         STD
         CALL DELAY
         CLD
         DEC AX
         CMP AX,0
         JNZ LOOP1
         MOV AX,0A
LOOP2:   STD
         CALL DELAY
         CLD
         STI
         CALL DELAY
         CLI
         STC
         CALL DELAY
         CLC
         DEC AX
         CMP AX,0
         JNZ LOOP2
         LEA DX,MSG2
         INT 10
         LEA DX,MSG3
         INT 10
         HLT
DELAY:   MOV CX,0010
LOOP3:   LOOP LOOP3
         RET
MSG1:    DW "ALERT: KLINGONS ON SCANNER",D,A,"$"
MSG2:    DW "ENEMY DESTROYED!!!",D,A,"$"
MSG3:    DW "SECTOR SECURED",D,A,"$"
         ORG 1000
         DW
