; SOURCE: testbcd1.asm
; AUTHOR: Dan Wooster
; DATE:   Dec 4, 1991
; This routine tests the packed BCD capabilities of the machine.

PRINT    equ 10
READ     equ 11
ATOB     equ 18
BTOA     equ 19
CR       equ 0A
LF       equ 0D

         setreg ip=begin
         setreg sp=5fff
         org 1000
begin:   lea dx,prompt
         int PRINT
         lea dx,bcdin1
         mov cx,10
         int READ
         lea si,bcdin1
         lea di,bcd1
         mov cx,10
         int ATOB
         lea si,bcd1
         lea di,bcdout1
         mov cx,20
         INT BTOA
         lea dx,msgout
         int PRINT
         hlt
prompt:  db "Enter a decimal number: $"
bcdin1:  db block 21 {0}
bcd1:    db block 10 {0}
         db ff
msgout:  db CR,LF,"Here is the number after conversions: "
bcdout1: db block 20 {0}
         db "$"
