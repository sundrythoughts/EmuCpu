; SOURCE: short1.asm
; AUTHOR: Dan Wooster
;
; sums a series of numbers in memory and stores result in AX
; end of series is indicated by a 0

        org 1000
        setreg ip = begin
        setreg sp = 5fff
begin:  mov si,0
        mov dx,0           ; used to compare with 0
        sub bx,bx
loop:   mov cx,nums[si]
        cmp cx,dx
        je  done
        add bx,cx
        inc si
        inc si
        jmp loop
done:   mov ax,bx
        hlt
        db 0
nums:   dw 10
        dw 03
        dw 04
        dw 05
        dw 20
        dw 0
        dw 0                ; dummy byte due to bug in assembler

        org 5000
        dw 0
