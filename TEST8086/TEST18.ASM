; SOURCE: test18.asm
; AUTHOR: Frank Walsh
;
; money changer program
; NOTE: will not assemble with my version of ASM

	SETREG IP = BEGIN
	SETREG SP = 5FFF
        ORG 100
	CR EQU %13       ; CARRIAGE RETURN
	LF EQU %10       ; LINE FEED
        ORG 100
	PROMPT1: DB "Enter amount under $"
	PROMPT2: DB "1.00: $"
	AMTSTR:	DB "       $"
	NUM: DB "$$$$"
	QUARTERS: DB CR,LF,"Quarters: $"
	DIMES: DB CR,LF,"Dimes:    $"
	NICKLES: DB CR,LF,"Nickles:  $"
	PENNIES: DB CR,LF,"Pennies:  $"

BEGIN:	LEA	DX,PROMPT1
	INT	10
	MOV	AL,'$'
	OUT	02,AL
	LEA	DX,PROMPT2
	INT	10
	LEA	DX,AMTSTR
	MOV	CX,0002
	INT	11
	INT	12
	LEA	DX,QUARTERS
	INT	10
        MOV	CL,19
	DIV	CL
	PUSH	AX
;	MOV	AL,AH
	SUB	AH,AH
	LEA	DX,NUM
	INT	13
	INT	10
	POP	AX
	MOV	AL,AH
	SUB	AH,AH
	LEA	DX,DIMES
	INT	10
        MOV	Cl,0A
	DIV	CL
	PUSH	AX
;	MOV	AL,AH
	SUB	AH,AH
	LEA	DX,NUM
	INT	13
	INT	10
	POP	AX
	MOV	AL,AH
	SUB	AH,AH
	LEA	DX,NICKLES
	INT	10
        MOV	Cl,05
	DIV	CL
	PUSH	AX
;	MOV	AL,AH
	SUB	AH,AH
	LEA	DX,NUM
	INT	13
	INT	10
	POP	AX
	MOV	AL,AH
	SUB	AH,AH
	LEA	DX,PENNIES
	INT	10
	LEA	DX,NUM
	INT	13
	INT	10
	HLT
