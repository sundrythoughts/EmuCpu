; music.ASM
; Demonstrate various 8086 instructions

     setreg ip = begin   ; sets the address of the first instruction to exec
     setreg sp = 5fff    ; sets the location of the stack
     org 1000            ; tells where to load program - hex 1000

sdoff: out  03,al
       inc  si
       inc  si
       jmp  till
begin: lea  bp,sound
       mov  bx,100
       mov  cx,speed
till:  mov  ax,[bp+si]
       cmp  ax,end
       jne  sdoff
       hlt

end:   dw 300
speed: dw 7000
sound: dw 20,40,60,80,100,120,140,160,180,200,220,240,260,280,300

      org 5000
      dw 0
