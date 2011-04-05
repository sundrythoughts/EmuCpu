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
`C   equ  %131 ;%261
`C#  EQU  %138 ;%277
`D   equ  %146 ;%293
`D#  EQU  %155 ;%310
`E-  equ  %158
`E   equ  %164 ;%329
`E#  EQU  %171
`F   EQU  %174 ;%348
`F#  equ  %185 ;%369
`G   equ  %196 ;%391
`G#  EQU  %207 ;%414
`A   equ  %219 ;%439
`A#  EQU  %233 ;%465
`B   equ  %246 ;%493
`B-  equ  %246

`C^  EQU  %261
`C#^ equ  %277 ;%555
`D^  equ  %293 ;%588
`D#^ EQU  %621

CR   equ  %13
LF   equ  %10

      org 1000

speed:    dw 7d0
notes:    dw `F, `F, `D, `D, `F, `F,`C,`C,`D,`E-,`F,`G,`A,`F
          DW `F,`F,`D,`D,`F,`F,`C,`C,`C^,`B,`C^,`D^,`G,`C^
          dw `F,`D^,`D^,`C^,`B-,`B-,`A,`A,`B-,`C^,`A,`G,`F,`B-
          dw `B-,`B-,`G,`G,`B-,`B-,`F,`F,`F,`G,`B-,`F,`C^,`B-
QUIT:     DW 0

DURATION: DW %8, %10, %16, %8, %8 ,%10,%16, %8, %8, %8, %8, %8, %8, %5
          DW %8, %10, %16, %8, %8 ,%10,%16, %8, %8, %8, %8, %8, %8, %5
          DW %8, %10, %16, %8, %8 ,%10,%16, %8, %8, %8, %8, %8, %8, %5
          DW %8, %10, %16, %8, %8 ,%10,%16, %8, %8, %8, %8, %8, %8, %5



credits:  db "'America The Beautiful'",CR,LF
          db " program by Robert Lardizabal",CR,LF
          db " $          лл",CR,LF
          db "            лл",CR,LF
          db "       лллллллллллл",CR,LF
          db "            лл",CR,LF
          db "            лл",CR,LF
          db "            лл",CR,LF
          db "            лл",CR,LF
          db "            лл","$"

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
        hlt