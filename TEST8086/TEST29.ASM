; SOURCE: cross.asm
; cross.asm - by J. E. Whaley

setreg ip=begin
setreg sp=5fff

CR   equ  %13
LF   equ  %10

      org 1000

cross:    db "       Christmas is the",CR,LF
          db "          C R O S S",CR,LF
          db "    program by J. E. Whaley",CR,LF,CR,LF
          db "             ���",CR,LF
 	  db "      For    ���    God",CR,LF
          db "             ���",CR,LF 
          db "    ���������������������",CR,LF
          db "             ���",CR,LF
          db "      so     ���    Loved",CR,LF
          db "             ���",CR,LF
          db "             ���",CR,LF
          db "      the    ���    World",CR,LF
          db "             ���",CR,LF
          db "             ���",CR,LF
          db "             ���",CR,LF,CR,LF
          db "    
          db "          John 3:16","$"

begin:  lea   dx,cross
        int   10
        hlt
