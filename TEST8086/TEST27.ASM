; SOURCE: test27.asm
; AUTHOR: Phil Egly
;
; computes factorial

              SETREG IP = BEGIN
              SETREG SP = 5FFF
              CR EQU %13
              LF EQU %10
              ORG 100
HEADER:       DB   "A Factorial Program by Phil Egly",CR,LF,"$"
PROMPT:       DB   "Enter a number between one and eight,",CR,LF,"$"
PROMPT2:      DB   "or a zero to quit ",CR,LF,"$"
ANSWER:       DB   " factorial is $"
NUMANS:       DB   "                 $"      ;tweaked by Samuel Fox here too
CARLNF:       DB   CR,LF,"$"
BEGIN:        LEA  DX,HEADER
              INT  10
LABEL1:       LEA  DX,PROMPT
              INT  10
              LEA  DX,PROMPT2
              INT  10
              Mov  Cx,%16        ; clear the numans area
ClearN:       Mov  Bp,Cx         ; write a 0 to this area
              Mov  byte NumAns[Bp],0  ; clear it !
              Loop ClearN        ; until done--tweak by Samuel Fox
              Sub  Ax,Ax         ; make sure Msb is 0
              IN   AX,01
              Sub  Ax,'0'        ;so you can type a 1-8 (tweak by Samuel Fox)
              CMP  AX,0000
              JE   ENDNG
              JL   LABEL1
              CMP  AX,0001
              JE   LABEL3
              CMP  AX,0008
              JG   LABEL1
              MOV  CX,AX
              MOV  BX,AX
              DEC  CX
LABEL2:       MUL  CX
              LOOP LABEL2
              PUSH AX
              MOV  AX,BX

              POP  AX
LABEL3:       LEA  DX,ANSWER
              INT  10

              Mov  Cx,%10
              Lea  Dx,NumAns     ; convert it to string
              Int  13            ;tweak by Samuel Fox
              Int  10            ; print the answer

              LEA  DX,CARLNF
              INT  10
              JMP  LABEL1
ENDNG:        HLT
              org 5000
              dw 0