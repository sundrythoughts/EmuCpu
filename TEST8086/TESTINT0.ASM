; testint0.asm
; tests divide error interrupt

     org 500
     setreg ip=begin
     setreg sp=5fff
begin: nop
; first test byte division
     mov ax,ffff
     mov cl,10
     div cl
     into

; test if int 0 returns to this instruction
     mov al,'1'
     out 2,al

; now test word division
     mov ax,ffff
     mov dx,ffff
     mov cx,234
     div cx
     into
     mov al,'2'
     out 2,al
     hlt

