; SOURCE: short2.asm
; AUTHOR: Dan Wooster
;
; counts the number of negative and positive numbers in a list
; places the number of neg in CH and number of pos in CL
; end of list is a -1
; *** Makes sure that odd addresses are handled properly


        org 1000
        setreg ip = begin
        setreg sp = 5fff
one:    db 1                  ; used to increment by 1
zero:   dw 0
begin:  mov di,0
        mov bx,ffff           ; used to compare with -1
        sub cx,cx
        sub dx,dx
loop:   mov ax,nums[di]
        cmp ax,bx
        je  done
        cmp ax,zero
        jl  neg
        add cl,one
        inc di
        inc di
        jmp loop
neg:    add ch,1
        inc di
        inc di
        jmp loop
done:   hlt
nums:   dw 10
        dw 03
        dw a930
        dw f899
        dw 04
        dw 05
        dw 7890
        dw 2005
        dw 123
        dw 456
        dw 980
        dw c993
        dw ffff
        dw 0             ; dummy byte - bug in assembler


