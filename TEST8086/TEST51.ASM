             PUSH	BP
          MOV	BP,SP
        MOV	AX,[BP-02]
         MOV	SP,BP
                        mov dx,num
                        mov cx,6
                        int 10
                        int 12
          POP	BP
          RET	

3522:0015 55            PUSH	BP
3522:0016 89E5          MOV	BP,SP
3522:0018 31C0          XOR	AX,AX

3522:001F 89EC          MOV	SP,BP
3522:0021 5D            POP	BP
3522:0022 C20200        RET	0002

3522:002A 55            PUSH	BP
3522:002B 89E5          MOV	BP,SP
3522:002D E8D0FF        CALL	0000
3522:0030 A33E00        MOV	[003E],AX
3522:0033 813E3E00F401  CMP	WORD PTR [003E],01F4
3522:0039 7E09          JLE	0044
3522:003B B80100        MOV	AX,0001
3522:003E 50            PUSH	AX
3522:003F E8D3FF        CALL	0015
3522:0042 EB17          JMP	005B
3522:0044 813E3E00F401  CMP	WORD PTR [003E],01F4
3522:004A 7508          JNZ	0054
3522:004C 31C0          XOR	AX,AX
3522:004E 50            PUSH	AX
3522:004F E8C3FF        CALL	0015
3522:0052 EB07          JMP	005B
3522:0054 B8FFFF        MOV	AX,FFFF
3522:0057 50            PUSH	AX
3522:0058 E8BAFF        CALL	0015
3522:005B 89EC          MOV	SP,BP
3522:005D 5D            POP	BP
3522:005E 31C0          XOR	AX,AX
