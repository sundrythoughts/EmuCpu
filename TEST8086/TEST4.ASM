; SOURCE: test4.asm
; AUTHOR: unknown
;
; tests register to register moves and the loop instruction
; results: ax=0059, bx=0037, cx=0000, dx=0059, ip = 0117

         SETREG    IP = 100
         ORG       100
         MOV AX,00
         MOV BX,00
         MOV CX,0A
         MOV DX,01
FIBIN:   ADD BX,DX
         MOV AX,BX
         MOV BX,DX
         MOV DX,AX
         LOOP FIBIN
         HLT
