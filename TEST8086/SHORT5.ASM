; SOURCE: short5.asm
; AUTHOR: Dan Wooster
;
; tests moving to memory by PUSHING the numbers 1 - 20 onto stack
; and then popping them and storing at memory location 1000

        org 1000
        setreg ip = begin
        setreg sp = 5fff
nums:   dw 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
begin:  mov di,0
        mov ax,0
        mov bx,%20
loop:   push ax
        inc di
        inc di
        inc ax
        cmp ax,bx
        jle  loop
        mov di,0
        mov cx,0          ; used in compare for end of loop
loop2:  pop dx
        mov nums[di],dx
        inc di
        inc di
        cmp dx,cx         ; zero
        jne loop2
done:   hlt
        dw 0
        org 5000
        dw 0
