; SOURCE: test21.asm
; AUTHOR: Michael Laird

; Simple calculator program written by Michael Laird
; Date: 11/88
; This program tests the following instructions:
;    lea  reg,mem
;    int  type
;    mov  reg,imm
;    mov  acc,imm
;    mov  mem,acc
;    mov  reg,reg
;    mov  reg,mem
;    cmp  acc,imm
;    cmp  acc,imm
;    jne
;    jmp
;    je
;    push reg
;    pop  reg
;    add  reg,reg
;    sub  reg,reg
;    mul  reg
;    div  reg
;    dec  reg
;    inc  reg
;    loop
;    hlt


CR equ %13
LF equ %10

SETREG     SP=5FFF
SETREG     IP=BEGIN

           ORG 1000
CREDITS:   DB "Super-simple Calculator",CR,LF
           DB "   By Michael Laird",CR,LF,"$"
PRMPT:     DB "Enter two numbers separated by an operator: $"
QPRMPT:    DB "Enter null to quit",CR,LF,"$"
RSPNSE:    DB "The answer is: "
ANS:       DB "      "
ENDIT:     DB CR,LF,"$"
OPER:      DB " "
ERROR:     DB "Error in expression",CR,LF,"$"
INSTR:     DB block %80 {0}
BYESTR:    DB "Bye! - Have a nice day!",CR,LF,"$"

BEGIN:     lea  dx,CREDITS
           int  10
           lea  dx,QPRMPT           ; prints stopping rule info
           int  10
           lea  dx,PRMPT            ; prompts user for expression
           int  10
           lea  dx,INSTR            ; reads expression
           mov  cx,%80
           int  11
WHILE:     mov  al,20
           mov  ah,20
           mov  ans,ax
           mov  ans+2,ax
           mov  ans+4,ax
           lea  dx,ENDIT
           int  10
           mov  ax,cx               ; move length to accum
           cmp  ax,0                ; quit if length zero
           jne  skipit              ;
           jmp  THEEND
skipit:    lea  dx,INSTR
           int  12                  ; str -> int1
           push ax                  ; save int1
           dec  cx
           add  dx,cx               ; skip over int just converted
tryagain:  mov  bp,dx
           mov  bl,[bp]             ; put operator in bl
           mov  al,bl
           cmp  al,'+'
           je   continue
           cmp  al,'-'
           je   continue
           cmp  al,'*'
           je   continue
           cmp  al,'/'
           je   continue
           inc  dx
           jmp  tryagain
continue:  inc  dx                  ; skip over operator
           int  12                  ; str -> int2
           push ax                  ; save int2
           mov  al,bl
           cmp  al,'+'              ; case operator of
           je   JADD                ;  +
           cmp  al,'-'              ;  -
           je   JSUB
           cmp  al,'*'              ;  *
           je   JMUL
           cmp  al,'/'              ;  /
           je   JDIV
JADD:      pop  bx                  ; add routine
           pop  ax
           add  ax,bx
           jmp  SKIP
JSUB:      pop  bx                  ; subtract routine
           pop  ax
           sub  ax,bx
           jmp  SKIP
JMUL:      pop  ax                  ; multiply routine
           pop  bx
           mul  bx
           jmp  SKIP
JDIV:      sub  dx,dx               ; divide routine
           pop  ax
           cmp  ax,0
           je   DIVBYZERO
           mov  bx,ax
           pop  ax
           div  bx
           jmp  SKIP
DIVBYZERO: lea  dx,ERROR            ; print error message
           int  10
           jmp  SKIP2
SKIP:      lea  dx,ANS              ; print result
           int  13
           lea  dx,RSPNSE
           int  10
SKIP2:     mov  al,20
           mov  ah,20
           mov  ans,ax
           mov  ans+2,ax
           mov  ans+4,ax
           lea  bp,instr
           mov  cx,%40
for:       mov  [bp],ax
           inc  bp
           inc  bp
           loop for
           lea  dx,PRMPT            ; prompt for next expression
           int  10
           lea  dx,INSTR
           mov  cx,%80
           int  11
           jmp  WHILE
THEEND:    lea  dx,BYESTR
           int  10
           hlt
