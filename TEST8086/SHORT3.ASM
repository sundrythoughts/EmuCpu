; SOURCE: short3.asm
; AUTHOR: Dan Wooster
;
; tests moving to memory by writing the numbers 1 - 20 at memory 1000

        org 1000
        setreg ip = begin
        setreg sp = 5fff
nums:   dw 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
begin:  mov di,0
        mov ax,0
        mov bx,14
loop:   mov nums[di],ax
        inc di
        inc di
        inc ax
        cmp ax,bx
        jle  loop
done:   hlt
        dw 0
        org 2000
        dw 0


