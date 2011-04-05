;Stephanie Harnden
;test41.asm

; ALL ERRORS ARE COMMENTED ON WAY OVER HERE ->
; (the comments are by where the error occurs...)

; one major error is that things don't get 
; re-initialized, so the program only comes
; closed to working how it was supposed to
; the first time it is run.

org 500
setreg ip=begin
setreg sp=5fff
cr equ %13
lf equ %10
READSTR EQU 11 
WRITESTR EQU 10 
READINT EQU 1C 
WRITEINT EQU 1A 
READLN EQU 1D 
WRITELN EQU 1B 
BCDADD EQU 14 
BCDSUB EQU 15 
ST2BCD EQU 18 
BCD2ST EQU 19 
ST2INT EQU 12 
INT2ST EQU 13 

HEADER:    db  "Adder by Stephanie Harndenn "
           db  "(modified Nov 2001 to use Sim86OS BCD routines by Mark Bidewell)",cr,lf,"$"
PROMPT1:   db  "Enter two decimal numbers separated by CR numbers (max 20 digits) ",cr,lf,"$"
NUMANS:    db  "                                ",cr,lf,"$"
BCDANS:    db  "                    ",ff
NUM1:      db  "                     $"
NUM2:      db  "                     $"
NUM1BCD:   db  "                    "
NUM2BCD:   db  "                    "
IMDone:    db  "All done",cr,lf,"$"

begin:  lea dx,HEADER
        int 10
label1: lea dx,PROMPT1
        int 10

        lea dx,NUM1                               
        mov cx,%20
        int 11

        lea dx,NUM2  
        mov cx,%20
        int 11

        lea si,NUM1
        lea di,NUM1BCD
        mov cx,%20
        int ST2BCD

        lea si,NUM2
        lea di,NUM2BCD
        mov cx,%20
        int ST2BCD

        lea si,NUM1BCD
        lea di,NUM2BCD
        lea bp,BCDANS
        mov cx, %20
        int BCDADD 

        lea si,BCDANS
        lea di,NUMANS
        mov cx,%20
        int BCD2ST

        lea dx,NUMANS
        int 10

done:   lea dx,IMDone
        int 10
        hlt

