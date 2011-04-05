;
; GROUP1.ASM
; TESTS THE BASIC EXECUTION OF GROUP I INSTRUCTIONS
; BY DONALD R. CONGDON 1990
;
         SETREG IP=MAIN
         SETREG SP=0100
         ORG 1000
;
; TESTS BYTEWISE MOV IMMEDIATE INSTRUCTIONS
;
MAIN:    MOV AL,55
         MOV BH,66
         MOV CL,88
;
; TESTS BYTEWISE MOV REG TO REG INSTRUCTIONS
;
         MOV AL,BH
         MOV CH,CL
         MOV AH,AL
;
; TESTS WORDWISE MOV IMMEDIATE INSTRUCTIONS
;
         MOV AX,1000
         MOV BX,2000
         MOV CX,3000
;
; TESTS WORDWISE MOV REG TO REG INSTRUCTIONS
;
         MOV AX,BX
         MOV CX,AX
;
; TESTS MEMORY TO REGISTER MOVES
;
         MOV AX,DATA1
         MOV BX,DATA2
;
; TESTS INDEXED MEMORY MOVES
;
         LEA BP,DATA1
         MOV CX,[BP]
         MOV BX,[BP][02]
;
; TESTS REGISTER TO MEMORY MOVES
;
         MOV AX,FFFF
         MOV DATA1,AX
         MOV AX,0000
         MOV AX,DATA1
;
; TESTS INDEXED REGISTER TO MEMORY MOVES
;
         LEA BX,DATA1
         MOV AX,1111
         MOV [BX],AX
         MOV [BX][02],AX
         MOV BX,DATA1
         MOV CX,DATA2
;
; TESTS FLAG PUSH AND POPS, LAHF, SAHF (MODIFICATIONS BY MARK BIDWELL 11/9/01)
;
         MOV AL,0
         MOV AH,FF
         SAHF               ; AF, CF, PF, SF, ZF ALL SET
         PUSHF              ; 00FF ON TOP OF STACK
         MOV AH,0
         SAHF               ; AF, CF, PF, SF, ZF ALL RESET
         POPF               ; AF, CF, PF, SF, ZF ALL SET
         LAHF               ; AH CONTAINS FF
;
; TESTS REGISTER PUSHES
;
         MOV AX,1000
         PUSH AX
         MOV AX,0000
         POP AX
;
; TESTS OUTPUT PORT
;
         MOV AL,%66
         OUT 02,AL
;
; TESTS INPUT PORT
;
         IN AL,01
         OUT 02,AL
;
; TESTS SOUND PORT
;
         MOV BX,1
         MOV CX,0500
         MOV AX,0200
         OUT 03,AX 

;
; Test LDS & LES
;
	PUSH DS
	LDS  CX,DATA1
	POP  DS
	LES  DX,DATA1

;  XCHG
	mov si, 5634
        mov di, 1222
        XCHG AX, BX
        XCHG [1068], CX
        xchg si,di

; XLAT
        mov al,1
        lea bx,data1    
        XLAT		;al should contain 11

         HLT
DATA1:   DW ABCD
DATA2:   DW DEF0
