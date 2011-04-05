; SOURCE: short7.asm
; AUTHOR: Dan Wooster
;
; tests short and long unconditional JMP instructions
; also tests CALL, RET and RET pop instructions

        org 1000
        setreg ip = begin
        setreg sp = 5fff
begin:  jmp   short
        hlt           ; better not halt here!
        hlt
        hlt
        hlt
short:  mov  ax,ffff  ; short jump made it
        jmp  long
        hlt           ; better not halt here either!
        org  3000
long:   mov ax,0      ; long jump made it
        call sub
        push ax
        push cx
        call subpop
        hlt
        org 4000
sub:    mov ax,ffff
        mov bx,ffff
        mov cx,ffff
        ret

subpop: mov ax,0
        mov bx,0
        mov cx,0
        ret 4

        dw 0
        org  500      ; just for fun!!! (bug)
        dw 0
