; SOURCE: test20.asm
;Title:   BUBBLE.ASM
;Author:  Georg Zimmer
;Date:    12/5/88

;Purpose: Asks user to input some numbers, then sorts them, and prints
;         them out.

        ;org 400
        ;setreg ip = begin
        ;setreg sp = 5000
        ;setreg si = 2
        ;setreg fl = 200
        
        SETREG IP = BEGIN
        SETREG SP = 5FFF
        SETREG FL = 0200
        SETREG SI = 2
        CR EQU %13
        LF EQU %10
        ORG 1000


;  *   define interrupt types   *

        atoi equ 12
        itoa equ 13
        strout equ 10
        strin equ 11

instructions:   db "Press enter on a blank line to quit ",cr,'$'
prompt:         db cr,lf,"Number: $"
results:        db cr,"Sorted list:",cr,lf,"$"
num:            dw block %30 {"gz"}
nums:           dw 00
textin:         db block %80 {"*"},'$'
numdec:         db "          ","$"

BEGIN:  lea dx,instructions
        int strout
        mov di,0
        mov si,2
getnumb: lea dx,prompt
        int strout
        mov cx,offset numdec - offset textin ; * get size of buffer
        lea dx,textin
        int strin
        jcxz blankline
        mov bx,cx
        mov textin[bx],si ;si is not a character, so it tells int atoi to stop
        int atoi
        mov num[di],ax
        add di,si       ;point to next word
        jmp getnumb

blankline: mov nums,di     ;save total number of numbers
        mov di,0

;this part sorts the numbers we read in

nexti:  mov bx,di
nextj:  add bx,si
        cmp bx,nums
        je jdone
        mov ax,num[bx]
        cmp ax,num[di]
        ja  nextj       ;ja = UNSIGNED jg !
                        ;swap
        mov cx,num[di]
        mov num[bx],cx
        mov num[di],ax
        jmp nextj

jdone:  add di,si
        cmp di,nums
        jl nexti
        jmp printout


;print sorted list
printout: mov di,0
        lea dx,results
        int strout

nextelement: mov ax,num[di]
        lea dx,numdec
        int itoa
        mov bx,cx       ;cx is offset of last char from decnum

        mov al,%13    ;put a CR at the end of the string
        mov ah,%10    ;put LF
        mov numdec[bx],ax
        int strout
        add di,si
        cmp di,nums
        jne nextelement
        hlt
            
