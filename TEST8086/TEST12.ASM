; SOURCE: test12.asm
; AUTHOR: unknown
;
; tests pushes and pops

setreg sp = 5fff
setreg ax = 10
setreg bx = 1a
setreg cx = 1f
setreg dx = af
setreg ip = begin
org 1000
begin:  push ax
        push bx
        push cx
        push dx
        pushf
        popf
        pop  ax
        pop  bx
        pop  cx
        pop  dx
        hlt
