   ; lab7.asm
   ; by Stephen Schaub
   setreg sp = 5fff
   setreg ip = main
   org 1000
   ;
   ;	int fact(int num)
   ;
fact:	push	bp
	mov	bp,sp
   ;
   ;	{
   ;	  if (num <= 1)
   ;
	cmp	word ptr [bp+4],1
	jg	@1@142
   ;
   ;	    return 1;
   ;
	mov	ax,1
@1@86:
	jmp	@1@170
	jmp	@1@170
@1@142:
   ;
   ;	  else
   ;	    return num * fact(num-1);
   ;
	mov	ax,word ptr [bp+4]
	dec	ax
	push	ax
	call	fact
	pop	cx
	mul	word ptr [bp+4]
	jmp	@1@86
@1@170:
   ;
   ;
   ;	}
   ;
	pop	bp
	ret
   ;
   ;	int main()
   ;
main:
	push	bp
	mov	bp,sp
	sub	sp,2
   ;	
   ;	{
   ;	  int n;
   ;	
   ;	  n = fact(getinput());
   ;
	lea     dx,prompt
	int     10
	lea     dx,val
	mov     cx,3
	int     11
	int     12
	push	ax
	call	fact
	pop	cx
	mov	word ptr [bp-2],ax
	lea     dx,outnum
	int     13
	lea     dx,outstr
	int     10
   ;
   ;	}
   ;
	mov	sp,bp
	pop	bp
	hlt
	org 500
prompt: db  c,"*** Factorial Computer ***",a,d,a,"Enter a small number:$"
val:    db block a {' '}
outstr: db  a,d,"The answer is: "
outnum: db block a {0}
	db "$"



