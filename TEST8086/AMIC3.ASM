; Jay French's amicable numbers program

  SETREG IP = MAIN
  SETREG SP = 0100
  ORG 1000

MAIN:
  jmp Maincondition
Mainwhile:
  push    si
  call SumOfDivisors
  pop cx
  cmp ax,di
  jne Maincondition
  push di
  call SumOfDivisors
  pop cx
  cmp ax,si
  jne Maincondition
  LEA DX,CRLF
  INT 10
  LEA DX,NUM
  MOV AX,SI
  INT 13
  MOV BX,CX
  MOV BYTE PTR NUM+BX,'$'
  INT 10
  MOV AL,' '
  OUT 2,AL
  OUT 2,AL
  LEA DX,NUM
  MOV AX,DI
  INT 13
  MOV BX,CX
  MOV BYTE PTR NUM+BX,'$'
  INT 10
Maincondition:
  LEA DX,PROMPT
  INT 10
  LEA DX,STRING
  MOV CX,20
  INT 11
  MOV BX,CX
  MOV BYTE PTR STRING+BX,'$'
  INT 12
  mov si,AX
  ADD DX,CX
  INT 12
	mov     di,AX
	or  si,si
	JNZ Mainwhile
  hlt

CRLF  : DB D, A, '$'
PROMPT: DB D, A, "Enter a pair of numbers seperated by spaces (0's to quit).$"
STRING: DB "                    $"
NUM:    DB "     $"

SumOfDivisors:
	push    bp
	mov     bp,sp
	push    si
	mov     si,word ptr [bp+4]
  xor cx,cx
	mov     bx,2
	jmp     SODcondition
SODforloop:
	mov     ax,si
	cwd
	div bx
	or  dx,dx
	jne NotZero
  add cx,bx
NotZero:
	inc     bx
SODcondition:
	cmp     bx,si
	jl SODforloop
	cmp     si,1
	jg GreaterThanOne
	xor     ax,ax
	jmp SODend
GreaterThanOne:
	inc     cx
	mov     ax,cx
SODend:
	pop     si
	pop     bp
	ret

