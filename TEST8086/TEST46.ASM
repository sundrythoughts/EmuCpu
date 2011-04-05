setreg ip=main
setreg sp=5FFF
org 100
   ;	
   ;	int isprime(unsigned int num)
   ;	
isprime:
	push	bp
	mov	bp,sp
	mov	cx,word ptr [bp+4]
   ;	
   ;	{
   ;	  unsigned int j;
   ;	  for (j=2;j<num;j++)
   ;	
	mov	bx,2
	jmp @1@170
@1@58:
   ;	
   ;	    if (num % j == 0)
   ;	
	mov	ax,cx
	xor	dx,dx
	div	bx
	or	dx,dx
	jne @1@142
   ;	
   ;	      return 0;
   ;	
	xor	ax,ax
@1@114:
	jmp @1@226
@1@142:
	inc	bx
@1@170:
	cmp	bx,cx
	jb @1@58
   ;	
   ;	  return 1;
   ;	
	mov	ax,1
	jmp @1@114
@1@226:
   ;	
   ;	}
   ;	
	pop	bp
	ret	
   ;	
   ;	void main()
   ;	
main:
	push	bp
	mov	bp,sp
	sub	sp,2
   ;	
   ;	{
   ;	int i;
   ;	for (i=2;i<25;i++)
   ;	
        lea     dx,str1
        int     10
        mov     cx,5
        mov     dx,str2
        int     11
        int     12
        xchg    ax,si
	mov	word ptr [bp-2],2
	jmp @2@142
@2@58:
   ;	
   ;	  if (isprime(i))
   ;	
	push	word ptr [bp-2]
	call isprime
	pop	cx
	or	ax,ax
	je @2@114
   ;	
   ;	    asm mov ax,i
   ;	
 	mov	 ax,[bp-2]
        lea      dx,str2
        int      13
        int      10
        lea      dx,crlf
        int      10
@2@114:
	inc	word ptr [bp-2]
@2@142:
	cmp	word ptr [bp-2],SI
	jl @2@58
   ;	
   ;	}
   ;	
	mov	sp,bp
	pop	bp
	hlt	
str1:
  db "Enter max number to check if prime$"
str2:
  db "        $"
crlf:
  db %13
  db %10
  db '$'

