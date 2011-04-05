; sampleIO.asm
; problem - read in 2 numbers, compute their sum, output answer
	READSTR EQU 11 
	WRITESTR EQU 10 
	READINT EQU 1C 
	WRITEINT EQU 1A 
	READLN EQU 1D 
	WRITELN EQU 1B 
	BCDADD EQU 14 
	BCDSUB EQU 15 
	STR2BCD EQU 18 
	BCD2ST EQU 19 
	STR2INT EQU 12 
	INT2STR EQU 13 

	CR EQU 12
	LF EQU 13
        org  1000
        setreg ip = main
        setreg sp = 5fff

inString1: db "          "
inString2: db "          "

summsg:  db "the sum is "
outsum:  db "       ",CR,LF,"$"


;
;	input 2 numbers as strings
;
main:	mov dx,offset instring1
	mov cx,%10
	int READSTR

	lea dx,instring2
	mov cx,%10
	int READSTR

;
;	convert each string to integer
;
	lea dx,instring1
	int STR2INT
	mov bx, ax

	lea dx,instring2
	int STR2INT

;
;	perform add
;
	add ax,bx

;
;	convert integer to string
;
	lea dx,outsum
	int INT2STR

;
;	output the string
;
	lea dx,summsg
	int WRITESTR

	hlt
