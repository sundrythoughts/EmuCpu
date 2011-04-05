; SOURCE: SumList.asm
; AUTHOR: CpS 310 Class of 2000
;
; using a subroutine to sum a list of numbers then output the result

CR EQU %13       ; CARRIAGE RETURN
LF EQU %10       ; LINE FEED

SETREG IP = BEGIN
SETREG SP = 5FFF
ORG 1000

;
; here's my output message area
;
RESULTMSG:    DB "The sum of numbers is "
SUMGOESHERE:  DB "       "
NEWLINE:      DB CR,LF,"$"
;
; here's the array of numbers
;
;    ARRAY:  DW BLOCK %10 {%55, %24, %18, %157, %386, %22, %77, %45, %2, %10, FC19}
ARRAY:  DW BLOCK %10 {%1, %1, %1, %1, %1, %1, %1, %1, %1, %1, FC19}

;
; subroutine to sum a bunch of numbers - stop at -999
; parm specs
;    BP contains the address of the list
;    place answer on top of stack
;
SUMEM:       PUSH BP  ; to retain its original value
             PUSH AX
             XOR  AX,AX   ; ZERO OUT OUR ACCUMULATOR
SUMLOOP:     CMP  WORD [BP],FC19
             JE   GOHOME
             ADD  AX,[BP]
             INC  BP
             INC  BP
             JMP  SUMLOOP

GOHOME:      MOV  BP,SP
             SS: MOV  [BP+6],AX   ; PUT ANSWER ON STACK FOR CALLING ROUTINE

             POP  AX
             POP  BP
             RET             

BEGIN:       LEA  BP,ARRAY
             CALL SUMEM
;
; CONVERT ANSWER FROM BINARY TO ASCII STRING
; DO THIS BY CALLING INT INT2ST
;   DX = ADDRESS FOR STRING
;   AX = NUM TO CONVERT
;   
              POP  AX
              LEA  DX,SUMGOESHERE
              INT  13    ; CONVER THE NUMBER
              LEA  DX,RESULTMSG
              INT  10
              HLT


              