; SOURCE: test19.asm
; AUTHOR: Frank Walsh
;
; sums numbers between 1 and n using n*(n-1)/2
; if n > 361 then divide overflow

	SETREG IP = BEGIN
	SETREG SP = 5FFF
        ORG 100
	CR EQU %13       ; CARRIAGE RETURN
	LF EQU %10       ; LINE FEED
        ORG 100
	PROMPT:		DB "ENTER A NUMBER N [0 <= N <= 361] : $"
	NEWLINE:	DB CR,LF,"$"
	SUMMSG:		DB CR,LF,"SUM OF FIRST N INTEGERS = "
	CONVSUM:	DB "$$$$$$$$"
	ORIGINALN:	DB "        "

BEGIN:	LEA	DX,PROMPT
	INT	10
	LEA	DX,ORIGINALN
	MOV	CX,0003
	INT	11
	INT	12
	MOV	DX,AX
	INC	AX
	MUL	DX
	MOV	CX,0002
	DIV	CX
	LEA	DX,CONVSUM
	INT	13
	LEA	DX,SUMMSG
	INT	10
	HLT