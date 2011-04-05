; SOURCE: test2.asm
; AUTHOR: Vickie Stratton
;
; adds the numbers from 1 to 100 and prints the result

org 1000
setreg ip =  begin
setreg sp = 5fff
prompt: DB a,d,"This adds numbers 1 to 100 $"
response: DB a,d,"The result is "
ans: DB "        $"
done: DB a,d,"Press a key to continue$"

begin: lea dx,prompt
      int 10
      mov cx, %100
      mov ax,0
   more:   add ax,cx
      dec cx
      jnz more
      lea dx,ans
      mov cx,6
      int 13
      lea dx,response
      int 10
      lea dx,done
      int 10
      in al,1
      hlt
      org 5000
      dw 0
