; SOURCE: test1.asm
;
; reads in a string and prints is out backwards

org 1000
setreg ip = begin
setreg sp = 5fff
prompt: DB "Enter your name $"
output: DB a,d,"Your name backwards is $"
input: DB BLOCK 80 {0}
done:  db a,d,"Press any key$"
begin:  lea dx,prompt
        int 10
        lea dx,input
        mov cx,80
        int 11
        push cx
        lea dx,output
        int 10
        pop cx
        lea si,input
        add si,cx
        inc cx
next:   mov al,[si]
        out 2,al
        dec si
        loop next
        lea dx,done
        int 10
        in al,1
        xchg ax,cx
        xchg bx,dx
        xchg cs,ds
        Hlt
