; SOURCE: tune.asm
; - by robert lardizabal
; plays "i have decided to follow jesus" using the following instructions:
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
`E   equ  %164 ;%329
`F   EQU  %174 ;%348
`F#  equ  %185 ;%369
`G   equ  %196 ;%391
`G#  EQU  %207 ;%414
`A   equ  %219 ;%439
`A#  EQU  %233 ;%465
`B   equ  %246 ;%493

`C^  EQU  %261
`C#^ equ  %277 ;%555
`D^  equ  %293 ;%588
`D#^ EQU  %621

CR   equ  %13
LF   equ  %10

      org 1000

speed:    dw 800
notes:    dw `C, `C, `E,  `G,  `G
          DW `G,  `A,  `G,  `E, `C
          dw `C^,`C^,`C^,`C^,`C^
          dw `C^,`D^, `C^,`A,  `G
          dw `C, `C, `E,  `G,  `G
          DW `G,  `A,  `G,  `E,  `C
          DW `G,  `A,  `G,  `E
          DW `C, `D,  `D,  `C,0
QUIT:     DW 0

DURATION: DW %4, %4, %4, %3, %2
          DW %4, %4, %4, %3, %2
          dw %4, %4, %4, %3, %2
          dw %4, %4, %4, %3, %2
          dw %4, %4, %4, %3, %2
          dw %4, %4, %4, %3, %2
          dw %4, %4, %4, %1
          dw %4, %4, %4, %1



credits:  db "'I Have Decided To Follow Jesus'",CR,LF
          db "         Folk Melody",CR,LF
          db "  program by Robert Lardizabal",CR,LF
          db "            лл",CR,LF
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
        hlt

        org 7000
        dw 0
