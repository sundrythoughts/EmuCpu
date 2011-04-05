; SOURCE: test25.asm
; AUTHOR: Phil Egly
;
; tests for primes

          SETREG IP = BEGIN
          SETREG SP = 5FFF
      CR  EQU  %13
      LF  EQU  %10
          ORG  100
HEADER:   DB   "Prime Number Tester by Phil Egly",CR,LF,"$"
PROMPT:   DB   "Enter n Number (1-65536)",CR,LF,"$"
PROMPT2:  DB   "Enter a zero to quit $"
THINK:    DB   CR,LF,"Thinking$"
PRIME2:   DB   CR,LF,"Is Prime",CR,LF,"$"
NOTPRIME: DB   CR,LF,"Is not Prime",CR,LF,"$"
BEGIN:    LEA  DX,HEADER
          INT  10
SECOND:   LEA  DX,PROMPT
          INT  10
          LEA  DX,PROMPT2
          INT  10
          IN   AX,01
          CMP  AX,0000
          JE   DONE
          LEA  DX,THINK
          INT  10
          CMP  AX,0001
          JE   PRIMENUM
          MOV  BX,AX
          MOV  CX,AX
          DEC  CX
LABEL1:   CMP  CX,0001
          JE   PRIMENUM
          MOV  AL,'.'
          OUT  02,AL
          SUB  DX,DX
          MOV  AX,BX
          DIV  CX
          CMP  DX,0000
          JE   ISNPRME
          LOOP LABEL1
PRIMENUM: LEA  DX,PRIME2
          INT  10
          JMP  ENDP
ISNPRME:  LEA  DX,NOTPRIME
          INT  10
ENDP:     JMP  SECOND
DONE:     HLT
