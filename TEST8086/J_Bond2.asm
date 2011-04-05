; SOURCE: tune2.asm
; - by robert lardizabal
;    plays "AMERICA THE BEAUTIFUL" using the following instructions:
;    mov reg,mem
;    lea reg,mem
;    out 3,ax     - uses a slightly non-standard implementation of the out;
;                   frequency = ax; duration = cx div bx
;    inc reg
;    cmp reg,mem
;    jne disp
;    hlt
;    int type

setreg ip=begin
setreg sp=5fff
`C2	EQU	039
`C#2	EQU	03C
`D2	EQU	040
`D#2 	EQU	043
`E-2	EQU	043
`E2	EQU	047
`F2 	EQU	04C
`E#2	EQU	04C
`F#2	EQU	050
`G2	EQU	055
`G#2	EQU	05A
`A2	EQU	05F
`A#2 	EQU	065
`B-2	EQU	065
`B2	EQU	06B
`C3	EQU	071
`C#3	EQU	078
`D3	EQU	07F
`D#3 	EQU	087
`E-3	EQU	087
`E3	EQU	08F
`F3 	EQU	097
`E#3	EQU	097
`F#3	EQU	0A0
`G3	EQU	0AA
`G#3	EQU	0B4
`A3	EQU	0BE
`A#3 	EQU	0CA
`B-3	EQU	0CA
`B3	EQU	0D6
`C4	EQU	0E2
`C#4	EQU	0F0
`D4	EQU	0FE
`D#4 	EQU	10D
`E-4	EQU	10D
`E4	EQU	11D
`F4 	EQU	12E
`E#4	EQU	12E
`F#4	EQU	140
`G4	EQU	153
`G#4	EQU	168
`A4	EQU	17D
`A#4 	EQU	194
`B-4	EQU	194
`B4	EQU	1AC
`C5	EQU	1C5
`C#5	EQU	1E0
`D5	EQU	1FC
`D#5 	EQU	211
`E-5	EQU	211
`E5	EQU	23B
`F5 	EQU	25D
`E#5	EQU	25D
`F#5	EQU	281
`G5	EQU	2A7
`G#5	EQU	2CF
`A5	EQU	2FA
`A#5 	EQU	327
`B-5	EQU	327
`B5	EQU	357
`C6	EQU	38A
`C#6	EQU	3C0
`D6	EQU	3F9
`D#6 	EQU	435
`E-6	EQU	435
`E6	EQU	475
`F6 	EQU	4B9
`E#6	EQU	4B9
`F#6	EQU	501
`G6	EQU	54E
`G#6	EQU	59E
`A6	EQU	5F3
`A#6 	EQU	64E
`B-6	EQU	64E
`B6	EQU	6AE
`R16	EQU	16
`R8	EQU	32
`R4	EQU	64
`R2	EQU	128

CR   equ  %13
LF   equ  %10

      org 1000

speed:    dw 600
notes:    dw `B4,`B4, `R16, `B3,`B4,`B4, `R16, `B3,`B4,`B4,`B4,`B4,`B4,`B3,`C4,
          DW `C#4,`C4,`B3,`C4,`C#4,`C4
          dw `E4,`F#4,`F#4,`F#4,`F#4,`E4,`E4,`E4
          dw `E4,`G4,`G4,`G4,`G4,`F#4,`F#4,`F#4
          dw `E4,`F#4,`F#4,`F#4,`F#4,`E4,`E4,`E4
	  dw `E4,`G4,`G4,`G4,`G4,`F#4,`F#4,`F#4
          dw `E4,`F#4,`F#4,`F#4,`F#4,`E4,`E4,`E4
	  dw `E4,`G4,`G4,`G4,`G4,`F#4,`F#4,`F#4
	  dw `D#5,`D5,`R16, `B4,`A4,`B4 
          dw `E4,`F#4,`F#4,`F#4,`F#4,`E4,`E4,`E4
	  dw `E4,`G4,`G4,`G4,`G4,`F#4,`F#4,`F#4
          dw `E4,`F#4,`F#4,`F#4,`F#4,`E4,`E4,`E4
	  dw `E4,`G4,`G4,`G4,`G4,`F#4,`F#4,`F#4   
	  dw `E4, `G4, `D#5, `D5, `G4
	  DW `A#4, `B4, `R4, `R8
	  DW `G4, `A4, `G4, `F#4, `B3, `E4, `C#4
QUIT:     DW 0


DURATION: DW %8, %8, %0, %3, %8, %8, %0, %3, %16, %8, %16, %8, %8, %2, %2
          DW %2, %2, %2, %2, %2, %2
	  DW %8, %16, %16, %8, %4, %8, %8, %8
	  DW %8, %16, %16, %8, %4, %8, %8, %8
	  DW %8, %16, %16, %8, %4, %8, %8, %8
	  DW %8, %16, %16, %8, %4, %8, %8, %8
	  DW %8, %16, %16, %8, %4, %8, %8, %8
	  DW %8, %16, %16, %8, %4, %8, %8, %8
	  DW %8, %2, %0, %8, %8, %1
	  DW %8, %16, %16, %8, %4, %8, %8, %8
	  DW %8, %16, %16, %8, %4, %8, %8, %8
	  DW %8, %16, %16, %8, %4, %8, %8, %8
	  DW %8, %16, %16, %8, %4, %8, %8, %8
	  DW %8, %4, %8, %3, %8
	  DW %8, %2, %0, %0
	  DW %8, %16, %16, %3, %8, %8, %1


credits:  db "    ******   ******   *******  =========================",CR,LF
db "   *******  *******  *******  ============",CR,LF
db "  **   **  **   **  *    **   (  |",CR,LF
db " **   **  **   **       **  ____/",CR,LF
db "*******  *******       **",CR,LF
db "******   ******       **    James Bond"
db "                        ","$"

begin:  nop
	;lea   dx,credits
        ;int   10
        mov   cx,speed
        lea   bp,duration
        lea   si,notes
	lea   di, credits
loop1:  mov   bx,[bp]
	mov   ax, [di]
        out	2, al
	inc   di
	mov   ax, [di]
        out	2, al
        mov   ax,[si]
	cmp	ax, `R16
	je wait
	cmp	ax, `R8
	je wait
	cmp	ax, `R4
	je wait
	cmp	ax, `R2
	je wait2
        out   3,ax
BackIn: inc   si
        inc   si
	inc   di
        inc   bp
        inc   bp        
        cmp   ax,quit
        jne   loop1
	jmp	end
wait2:  push    ax
WAIT:	dec	ax
	cmp	ax,0
	jnz	wait
	pop     ax
	jmp	BackIn
end:    hlt
