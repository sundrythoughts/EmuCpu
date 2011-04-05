; SOURCE: testsegs.asm
; AUTHOR: Mr Wooster
; DESC:   tests your handling of segment registers
; NOTE: modified the obj file on 12/2/99 by Bill Cook to fix seg problem - DO NOT REASSEMBLE unless you want to dig deep into the problem this will cause you!!!
; due to a bug in ASM86, we must fix up the .obj file by placing the segment register indicator bytes in the right spot - that's a lot of fun!! NOT
;

       org  0010
       setreg IP = begin
       setreg SP = 0fff
       setreg CS = 0001
       setreg DS = 00A0
       setreg ES = 0100
       setreg SS = 0500

begin: mov  ax,value1      ; load the value ABCD into AX
       mov  bx,1234        ; load the value 1234 into BX
       mov  value2,bx      ; store 1234 at 00A0:0002
       push ax             ; store ABCD at 0500:0FFF
       push bx             ; store 1234 at 0500:0FFD
       pop  cx             ; load 1234 into CX
       es:mov  dx,num      ; load the value 4567 into DX
       hlt

; DS
       org 0120
value1: dw abcd
value2: dw 0000

; ES
       org 0f00                      
num:    dw 4567
