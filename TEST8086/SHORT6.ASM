; SOURCE: short6.asm
; AUTHOR: Dan Wooster
;
; tests OUT and LOOP instruction by outputing alphabet

        org 1000
        setreg ip = begin
        setreg sp = 5fff
begin:  mov cx,%26        ; number of letters in alphabet
        mov al,'A'        ; first letter of alphabet
again:   out 2,al
        inc al
        loop again
        hlt
        dw 0
