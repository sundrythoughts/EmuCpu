;Test routine by Daniel Mulfinger
;Calculates the nth term of the Fibonacci sequence
;NOTE: tests sign extend mode on the CMP instruction
;
;Note - This program is recursive and therefore slow.
;   As higher numbers are chosen, the run time increases exponentially
;
;  C source
;
;#include <stdio.h>
;
;int Fib(int x)
;{
;   if (x<=1)
;      return(x);
;   else
;      return(Fib(x-1)+Fib(x-2));
;}
;
;main()
;{
;   static int i;
;   printf("Enter a number (under 25):  ");
;   scanf("%d",&i);
;   printf("Term %d of the Fibonacci sequence is %d",i,Fib(i));
;}



setreg IP=BEGIN
setreg SP=5000

org 1000

prompt: db "Enter a number (under 25): $"
output: db 0d
	db 0a
	db "Term "
term:   db "   of the Fibonacci sequence is "
answer: db "      $"
number: db 0

BEGIN:
	lea     dx,prompt
	int     10
	lea     dx,term
	mov     cx,2
	int     11
	lea     dx,term
	int     12
	push	ax
	call	Fib
	pop	cx
	lea     dx,answer
	mov     cx,6
	int     13
	lea     dx,output
	int     10
	hlt

Fib:
	push	bp
	mov	bp,sp
	push	si
	mov	si,word ptr [bp+4]
	cmp	si,1
	jg	label2
	mov	ax,si
	jmp	short label1
	jmp	short label3
label2:
	mov	ax,si
	dec	ax
	push	ax
	call	Fib
	pop	cx
	push	ax
	mov	ax,si
	add	ax,-2
	push	ax
	call	Fib
	pop	cx
	mov	dx,ax
	pop	ax
	add	ax,dx
	jmp	short label1
label3:
label1:
	pop	si
	pop	bp
	ret

