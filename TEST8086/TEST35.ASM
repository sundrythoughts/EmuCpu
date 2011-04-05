;
; FIBONACC.ASM
; COMPUTES THE FIRST FIVE FIBONACCI NUMBERS
; RESULTS ARE DISPLAYED IN THE AX REGISTER
; BY DONALD R. CONGDON 1990
;
         ORG 1000
         SETREG IP=MAIN
         SETREG SP=0100
MAIN:    MOV BX,0000              ; FIRST FIBONACCI TERM
         MOV CX,0001              ; SECOND FIBONACCI TERM
         MOV SI,0000
         LEA DX,MSG1
         INT 10
         LEA DX,MSG2
         INT 10
         MOV DX,0000
AGAIN:   MOV SI,BX
         ADD SI,CX
         PUSH DX
         LEA DX,MSG3
         INT 10
         LEA DX,MSG4
         INT 10
         IN AL,01
         POP DX
         MOV BX,CX
         MOV CX,SI 
         INC DX
         MOV AX,DX   
         CMP AX,%5 
         JE END1
         JMP AGAIN
END1:    LEA DX,MSG5
         INT 10
         HLT
MSG1:    DW "        FIBONACCI",A,D,"$"
MSG2:    DW "THE RESULTS ARE IN SI",A,D,"$"    
MSG3:    DW "RESULT NOW AVAILABLE",A,D,"$"
MSG4:    DW "---PRESS A KEY---",A,D,"$"
MSG5:    DW "THAT'S ALL FOLKS!",A,D,"$"
         ORG 5000
         DW
