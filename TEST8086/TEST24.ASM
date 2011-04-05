; SOURCE: test24.asm
; joy.asm - by Michael Laird
; plays "Joy to the World" using the following instructions:
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
`C#  equ  %139 ;%277
`D   equ  %147 ;%294
`E   equ  %165 ;%330
`F#  equ  %186 ;%371
`G   equ  %196 ;%392
`A   equ  %220 ;%440
`B   equ  %247 ;%494
`C#^ equ  %277 ;%555
`D^  equ  %294 ;%588

CR   equ  %13
LF   equ  %10

      org 1000

speed:    dw 700
notes:    dw `D^,`C#^,`B,  `A, `G,  `F#,`E,`D, `A, `B, `B,  `C#^,`C#^,`D^
          dw `D^,`D^, `C#^,`B, `A,  `A, `G,`F#,`D^,`D^,`C#^,`B,  `A,  `A, `G,
          dw `F#,`F#, `F#, `F#,`F#, `F#,`G,`A, `G, `F#,`E,  `E,  `E,  `E, `F#,
          dw `G ,`F#, `E,  `D, `D^, `B, `A,`G, `F#,`G, `F#, `E,  `D,   0
quit:     dw 0

duration: dw  %4,%5,%16,%3,%8,%4,%4,%3,%8,%3,%8,%3,%8,%3
          dw  %8,%8,%8,%8,%8,%5,%16,%8,%8,%8,%8,%8,%8,%5,%16,%16
          dw  %8,%8,%8,%8,%16,%16,%3,%16,%16,%8,%8,%8,%16,%16,%3
          dw  %16,%16,%8,%3,%8,%5,%16,%8,%8,%4,%4,%2

credits:  db "      'Joy to the World'",CR,LF
          db "       by G. F. Handel",CR,LF
          db "   program by Michael Laird",CR,LF
          db "        ммлллллллллмм",CR,LF
          db "     мллллл*лллл*ллллллм",CR,LF
          db "   лллл*ллллппппплллл*лллл",CR,LF
          db "  лл*ллллп         пллллллл",CR,LF
          db " ллллллл    Merry    ллл*ллл",CR,LF
          db "лл*лллл               ллллллл",CR,LF
          db "ллллллл   Christmas   ллл*ллл",CR,LF
          db " ллл*ллл             ллллллл",CR,LF
          db "  лллллллм         мллл*ллл",CR,LF
          db "   ллллл*лллмммммллл*ллллл",CR,LF
          db "     плллллл*ллл*ллллллп",CR,LF
          db "         пплллллллпп","$"

begin:  lea   dx,credits
        int   10
        mov   cx,speed
        lea   bp,duration
        lea   si,notes
loop1:  mov   bx,[bp]
        mov   ax,[si]
        out   3,ax
        inc   si
        inc   si
        inc   bp
        inc   bp
        cmp   ax,quit
        jne   loop1
        hlt
        org 5000
        dw 0
