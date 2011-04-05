; SOURCE: test16.asm
; AUTHOR: Stig
;
; input numbers until 0 and prints max

org  1000
setreg IP = begin
setreg SP = 5fff
count:   dw 0
string:  db "        $"
title:   db a,d,"Test routine by Stig Thormodsrud"
         db a,d,"To find maximum number entered$"
prompt:  db a,d,"Enter a number, 0 to quit$"
answer:  db a,d,"The maximum is "
max:     db "          $"
begin:   mov  bx,ffff
         lea  dx,title
         int  10
next:    lea  dx,prompt
         int  10
         ; need to clear out string space each time
         lea bp,string
         mov byte [bp],' '
         mov byte [bp+1],' '
         mov byte [bp+2],' '
         mov byte [bp+3],' '
         mov byte [bp+4],' '
         mov byte [bp+5],' '
         lea  dx,string
         mov  cx,6
         int  11
         lea  dx,string
         mov  cx,6
         int  12
         cmp  ax,0
         je   done
         cmp  ax,bx
         jng  next
         mov  bx,ax
         jmp  next
done:    mov  ax,bx
         lea  dx,max
         mov  cx,6
         int  13
         lea  dx,answer
         int  10
         hlt


