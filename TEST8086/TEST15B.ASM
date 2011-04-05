; SOURCE: test15.asm
; AUTHOR: Stig
;
; adds numbers input until a 0

org  1000
setreg IP = main
setreg SP = 5fff
count:   dw 0
string:  db "        $"
title:   db a,d,"Test routine by Stig Thormodsrud"
	 db a,d,"To add numbers$"
prompt:  db a,d,"Enter a number, 0 to quit$"
answer:  db a,d,"The sum is "
result:  db "          $"
main:   lea  dx,title
	int  10
	mov  ax,0
	mov  bx,ax
next:   lea  dx,prompt
	int  10
	lea  dx,string
	mov  cx,6
	int  11
	lea  dx,string
	int  12
	cmp  ax,30
	je   done
	add  bx,ax
	jmp  next
done:   mov  ax,bx
	lea  dx,result
	mov  cx,6
	int  13
	lea  dx,answer
	int  10
	hlt
