; AUTHOR:  Tim Callahan
; DATE:    December 5, 1988
; DESCRIPTION:  This program will test all of the conditional jumps as well
;               as the unconditional jump.  If any of your jumps do not work
;               correctly, you will hear a beep(s) from your output speaker.
;               If you make it through the entire test program correctly, you
;               will see a message appear on your screen saying, "Congradula-
;               tions!!  You made it to the end!".  Good Luck debugging!!!!
;               NOTE:  THIS PROGRAM DOES NOT TEST THE CONDITION OF THE PF!!

         org       1000
         setreg    ip = begin
         setreg    sp = 5FFF
correct: db        "Congradulations!!  You made it to the end!$"
begin:   mov       ax,104
         push      ax
         popf                      ;sets the parity and trap flags
         mov       cx,100          ;makes sure the CX register is not zero
         mov       ax,200
         mov       bx,100
         cmp       ax,bx
         jb        wrong
         jbe       wrong
         jc        wrong
         jcxz      wrong
         je        wrong
         jl        wrong
         jle       wrong
         jo        wrong
         js        wrong
         ja        right1
         jmp       wrong
right1:  jae       right2
         jmp       wrong
right2:  jg        right3
         jmp       wrong
right3:  jge       right4
         jmp       wrong
right4:  jnz       right5
         jmp       wrong
right5:  jno       right6
         jmp       wrong
right6:  jns       right7
         jmp       wrong
right7:  jmp       begin2
wrong:   mov       ax,1000
         out       3,ax
         hlt
begin2:  mov       cx,0    ;makes sure the CX register is zero
         mov       dx,0
         push      dx
         popf
         cmp       bx,ax
         ja        wrong
         jae       wrong
         jg        wrong
         jge       wrong
         jns       wrong
         je        wrong
         jo        wrong
         jb        right8
         jmp       wrong
right8:  jbe       right9
         jmp       wrong
right9:  jc        right10
         jmp       wrong
right10: jcxz      right11
         jmp       wrong
right11: jl        right12
         jmp       wrong
right12: jle       right14
         jmp       wrong
right14: js        right15
         jmp       wrong
right15: jnz       right16
         jmp       wrong
right16: jno       right17
         jmp       wrong
right17: jmp       begin3
         jmp       wrong
begin3:  mov       ax,FFFF
         cmp       ax,FFFF
         ja        wrong
         jb        wrong
         jg        wrong
         jl        wrong
         jne       wrong
         jo        wrong
         js        wrong
         je        right18
         jmp       wrong
right18: jge       right19
         jmp       wrong
right19: jle       right20
         jmp       wrong
right20: jnc       right21
         jmp       wrong
right21: jno       right22
         jmp       wrong
right22: jns       right23
         jmp       wrong
right23: jae       right24
         jmp       wrong
right24: jbe       right25
         jmp       wrong
right25: lea       dx,correct
         int       10
         hlt




