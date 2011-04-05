;
; GROUP4.ASM
; TESTS GROUP IV INSTRUCTIONS
; BY DONALD R. CONGDON 1990
; 
; UPDATED BY DAVID CLARK TO TEST ALL CONDITIONAL JUMPS 11/2002

         SETREG IP=MAIN
         SETREG SP=0100
         ORG 1000
MAIN:    CALL SUB1
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
END:  MOV CX, 2

LOOPZL: CMP CX, CX
        LOOPZ LOOPZL
        
        MOV AX, 1
        MOV CX, 2
LOOPNZL: CMP AX, CX
        LOOPNZ LOOPNZL
        
        MOV AX, 2
JNBEL: CMP  AX, 1   
          MOV AX, 1
          JNBE JNBEL
          
JNBL:   CMP AX, 1
        MOV AX, 0
        JNB JNBL

JNAEL: CMP AX, 3
        MOV AX, 4
        JNAE JNAEL
        
JNAL: CMP AX, 5
        MOV AX, 6
        JNA JNAL
        
        MOV AX, FFFF
JCL: ADD AX, 1
        JC JCL


        MOV CX, FFFF
JCXZL:  INC CX
        JCXZ JCXZL
        
JEL:    CMP CX, 1
        INC CX
        JE JEL
        
JGL: CMP CX, 1
        DEC CX
        JG JGL

JGEL: CMP CX, 1
        DEC CX
        JGE JGEL
        
JLL:   CMP CX, 1
        INC CX
        JL JLL
        
JLEL:   CMP CX, 1
        INC CX
        JLE JLEL
        
        MOV CX, FFFE
JNCL: ADD CX, 1
        JNC JNCL
        
JNEL: CMP CX, 1
        MOV CX, 1
        JNE JNEL
            
        MOV CX, 5598
JNOL: CMP CH, CL
        MOV CX, 5599
        JNO JNOL

        MOV CX, 1
JNSL: DEC CX
        JNS JNSL
        
        XOR CX, CX
JNPL: INC CX
        JNP JNPL
        
        MOV CX, 99
JOL:  CMP CX, 55
        INC CX
        JO JOL

        MOV CX, 2
JPEL: INC CX
        JPE JPEL
        
        MOV CX, 1
JSL:    CMP CX, 2
        MOV CX, 3
        JS JSL


        LEA DX,MSG7
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
MSGCFAR: DW "CALL FAR WAS SUCCESS", D, A, "$"