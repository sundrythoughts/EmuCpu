;
; SOUND.ASM
; TESTS THE SOUND OUTPUT AND INDEXED ADDRESSING
; BY DONALD R. CONGDON 1990
;
         SETREG IP=MAIN
         SETREG SP=0100
         ORG 1000
MAIN:                   
         LEA DX,MSG1
         INT 10
         LEA DX,MSG2
         INT 10
         MOV DX,0000
         LEA BP,NOTES
         LEA SI,DURS
LOOP1:   MOV AX,[BP]
         MOV CX,[SI]
         MOV BX,0001
         OUT 03,AL
         INC BP
         INC BP
         INC SI
         INC SI
         INC DX
         MOV AX,DX
         CMP AX,%10      ;CHECK FOR END OF TABLE
         JNE LOOP1
         HLT
NOTES:   DW %100
         DW %110
         DW %120
         DW %130
         DW %140
         DW %150
         DW %160
         DW %170
         DW %180
         DW %190
DURS:    DW 0200
         DW 0100
         DW 0200
         DW 0100
         DW 0200
         DW 0050
         DW 0100
         DW 0050
         DW 0100
         DW 0500
MSG1:    DW "SICKENING SOUNDS",A,D,"$"
MSG2:    DW "    TO DELIGHT THE MIND",A,D,"$"
         ORG 5000
         DW
