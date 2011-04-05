        setreg sp = 5FFF
        setreg ip = 0100
        ORG 100
        MOV AX, BY
        MOV AX,0
        PUSH AX
        MOV AX,5
        PUSH AX
        CALL SUMALL
        HLT
SUMALL: NOP
        POP BX
        POP CX
        POP AX
        PUSH BX
        ADD AX,CX
        DEC CX
        JCXZ DONE
        PUSH AX
        PUSH CX
        CALL SUMALL
DONE:   NOP
        RET
BY:     DB "GEORG ZIMMER",0
