; SOURCE: test3.asm
; AUTHOR: Vickie Stratton
;
; plays the Hi/Lo Guessing Game with a preset number

org 1000
setreg ip=begin
setreg sp = 5fff
prompt: DB a,d,"Enter the Magical Number $"
response: DB a,d,"Congratulations !  You guessed in only "
numtries: DB "     $"
finished: DB a,d,"Press a key to continue$"
hi: DB a,d,"Too high!  Guess Again $"
lo: DB a,d," Too Low!  Guess Again $"
guess: DB "      "
count: DW 0
       done: mov ax,count
           lea dx,numtries
           int 13
           lea dx,response
           int 10
           lea dx,finished
           int 10
           in al,1
           hlt
       hgue: lea dx,hi
            int 10
            jmp begin

      lgue: lea dx,lo
            int 10
            jmp begin
            dw 0
begin: lea dx,prompt
       int 10
       lea dx,guess
       mov cx,6
       int 11
       ; clear next byte after number to prevent interference
       ; added by Sarah Matzko 12/9/99
       mov bp, cx
       mov BYTE PTR [guess + bp], 20
       mov ax,count
       inc ax
       mov count,ax
       lea dx,guess
       int 12
       cmp ax,%15
       je done
       jl lgue
       jg hgue


