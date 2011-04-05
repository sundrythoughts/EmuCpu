; SOURCE: test22.asm
; Random number generator
; by Michael Laird
; Date: 11/88
; This program generates pseudo-random numbers and prints them out
;
; This program tests the following instructions:
;    push  reg
;    mov   reg,imm
;    sub   reg,reg
;    div   reg
;    add   reg,imm
;    inc   reg
;    mov   mem,reg
;    dec   reg
;    cmp   acc,imm
;    jnz   disp
;    mov   reg,mem
;    out   2,al
;    loop  disp
;    mov   acc,imm
;    pop   reg
;    ret
;    hlt
;    mul   reg
;    mov   reg,reg
;    call  disp
;    jmp   disp
;    lea   reg,mem

CR equ %13
LF equ %10
setreg ip=begin
setreg sp=5fff
       org 1000
temp:  db "      "
msg1:  db "Random number generator",CR,LF,"$"
msg2:  db "   By Michael Laird",CR,LF,"$"

printint: push  ax
          push  bx
          push  cx
          push  dx
          lea   si,temp+5
          mov   bx,a
          sub   cx,cx
loop1:    sub   dx,dx
          div   bx
          add   dl,30
          inc   cx
          mov   [si],dl
          dec   si
          cmp   ax,0
          jnz   loop1
          inc   si
loop2:    mov   al,[si]
          out   2,al
          inc   si
          loop  loop2
          mov   al,0a
          out   2,al
          mov   al,0d
          out   2,al
          pop   dx
          pop   cx
          pop   bx
          pop   ax
          ret

begin:    lea   dx,msg1
          int   10
          lea   dx,msg2
          int   10
          mov   bx,1000
          mov   cx,1234
          mov   ax,4321
          sub   dx,dx
loop3:    mul   cx
          div   bx
          inc   dx
          mov   ax,dx
          call  printint
          inc   cx
          jmp   loop3
          hlt
