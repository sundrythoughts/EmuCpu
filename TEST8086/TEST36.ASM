;
; TRANSP.ASM
; TAKES AN INPUTTED STRING AND REVERSES IT
; BY DONALD R. CONGDON 1990
;
         SETREG IP=MAIN
         SETREG SP=0100
         ORG 1000
MAIN:    LEA DX,MSG1
         INT 10
         LEA DX,MSG2
         INT 10
         LEA DX,BUFFER         ; GET STRING
         MOV CX,8
         INT 11
         LEA DX,MSG3
         INT 10
         LEA AX,BUFFER          ; GET STRING BUFFER
         LEA SI,BUFFER2        ; GET DESTINATION BUFFER
         ADD AX,7
         MOV BP,AX
         MOV DX,8              ; NUMBER OF CHARACTERS
LOOP1:   MOV AL,[BP]
         MOV [SI],AL
         INC SI
         DEC BP
         DEC DX
         MOV AX,DX
         CMP AX,0
         JNE LOOP1
         LEA DX,BUFFER2
         INT 10
         HLT
MSG1:    DW "    STRING REVERSER",A,D,"$"
MSG2:    DW "ENTER AN 8 CHAR STRING",A,D,"$"
MSG3:    DW "NOW REVERSING.....",A,D,"$"
BUFFER:  DW "        "
BUFFER2: DW "        ",A,D,"$"
         ORG 1000
         DW

