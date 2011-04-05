; AUTHOR: DAN WOOSTER
; DATE:   12/1/88
;         added BCD routines 11/30/91
;
; PURPOSE: CREATES INITIAL LOAD FILE FOR STUDENT 8086 SIMULATOR
;          IT INITIALIZES THE INTERRUPT VECTOR AND SEVERAL INTERRUPT
;          SERVICE ROUTINES
;
	 SETREG DS = 0
	 SETREG SS = 0
	 SETREG CS = 0
	 SETREG SP = 5FFF

	 CR EQU %13       ; CARRIAGE RETURN
	 LF EQU %10       ; LINE FEED
	 ORG 0            ; INTERRUPT VECTOR
	 DW  offset TYPE0,0
	 DW  offset TYPE1,0
	 DW  offset TYPE2,0
	 DW  offset TYPE3,0
	 DW  offset TYPE4,0
	 DW  offset TYPE5,0
	 DW  offset TYPE6,0
	 DW  offset TYPE7,0
	 DW  offset TYPE8,0
	 DW  offset TYPE9,0
	 DW  offset INVALID,0
	 DW  offset INVALID,0
	 DW  offset INVALID,0
	 DW  offset INVALID,0
	 DW  offset INVALID,0
	 DW  offset INVALID,0
	 DW  offset XPRINT,0      ; TYPE 10 - Print String
	 DW  offset XREAD,0       ; TYPE 11 - Read String
	 DW  offset XDECI,0       ; TYPE 12 - String-&gt;Integer
	 DW  offset XDECO,0       ; TYPE 13 - Integer-&gt;String
	 DW  offset BCDADD,0      ; TYPE 14 - Add packed BCD
	 DW  offset BCDSUB,0      ; Type 15 - Subtract packed BCD
	 DW  offset INVALID,0      ; Type 16 - Multiply packed BCD
	 DW  offset INVALID,0      ; Type 17 - Divide packed BCD
	 DW  offset BCDI,0        ; Type 18 - String-&gt;BCD
	 DW  offset BCDO,0        ; Type 19 - BCD-&gt;String
	 DW  offset WRITEINT,0    ; Type 1a - Write integer
	 DW  offset WRITELN,0     ; Type 1b - Write new line
	 DW  offset READINT,0     ; Type 1c - Read integer
	 DW  offset READLN,0      ; Type 1d - Read new line
	 ORG 6000
;
; INTERRUPT HANDLER MESSAGES
;
MSG0:    DB  "TYPE 0 INTERRUPT",CR,LF,"$"
MSG1:    DB  "TYPE 1 INTERRUPT",CR,LF,"$"
MSG2:    DB  "TYPE 2 INTERRUPT",CR,LF,"$"
MSG3:    DB  "TYPE 3 INTERRUPT",CR,LF,"$"
MSG4:    DB  "TYPE 4 INTERRUPT",CR,LF,"$"
MSG5:    DB  "TYPE 5 INTERRUPT",CR,LF,"$"
MSG6:    DB  "TYPE 6 INTERRUPT",CR,LF,"$"
MSG7:    DB  "TYPE 7 INTERRUPT",CR,LF,"$"
MSG8:    DB  "TYPE 8 INTERRUPT",CR,LF,"$"
MSG9:    DB  "TYPE 9 INTERRUPT",CR,LF,"$"
MSGX:    DB  "INVALID INTERRUPT",CR,LF,"$"

;
; TYPE 0 INTERRUPT
;
TYPE0:   CLI
	 PUSH DS
	 PUSH DX
	 MOV  DX,0
	 PUSH DX
	 POP  DS
	 LEA  DX,MSG0
	 INT  10
	 POP  DX
	 POP  DS
	 STI
	 IRET

;
; TYPE 1 INTERRUPT
;
TYPE1:   CLI
	 PUSH DS
	 PUSH DX
	 MOV  DX,0
	 PUSH DX
	 POP  DS
	 LEA  DX,MSG1
	 INT  10
	 POP  DX
	 POP  DS
	 STI
	 IRET

;
; TYPE 2 INTERRUPT
;
TYPE2:   CLI
	 PUSH DS
	 PUSH DX
	 MOV  DX,0
	 PUSH DX
	 POP  DS
	 LEA  DX,MSG2
	 INT  10
	 POP  DX
	 POP  DS
	 STI
	 IRET

;
; TYPE 3 INTERRUPT
;
TYPE3:   CLI
	 PUSH DS
	 PUSH DX
	 MOV  DX,0
	 PUSH DX
	 POP  DS
	 LEA  DX,MSG3
	 INT  10
	 POP  DX
	 POP  DS
	 STI
	 IRET

;
; TYPE 4 INTERRUPT
;
TYPE4:   CLI
	 PUSH DS
	 PUSH DX
	 MOV  DX,0
	 PUSH DX
	 POP  DS
	 LEA  DX,MSG4
	 INT  10
	 POP  DX
	 POP  DS
	 STI
	 IRET

;
; TYPE 5 INTERRUPT
;
TYPE5:   CLI
	 PUSH DS
	 PUSH DX
	 MOV  DX,0
	 PUSH DX
	 POP  DS
	 LEA  DX,MSG5
	 INT  10
	 POP  DX
	 POP  DS
	 STI
	 IRET

;
; TYPE 6 INTERRUPT
;
TYPE6:   CLI
	 PUSH DS
	 PUSH DX
	 MOV  DX,0
	 PUSH DX
	 POP  DS
	 LEA  DX,MSG6
	 INT  10
	 POP  DX
	 POP  DS
	 STI
	 IRET

;
; TYPE 7 INTERRUPT
;
TYPE7:   CLI
	 PUSH DS
	 PUSH DX
	 MOV  DX,0
	 PUSH DX
	 POP  DS
	 LEA  DX,MSG7
	 INT  10
	 POP  DX
	 POP  DS
	 STI
	 IRET

;
; TYPE 8 INTERRUPT
;
TYPE8:   CLI
	 PUSH DS
	 PUSH DX
	 MOV  DX,0
	 PUSH DX
	 POP  DS
	 LEA  DX,MSG8
	 INT  10
	 POP  DX
	 POP  DS
	 STI
	 IRET

;
; TYPE 9 INTERRUPT
;
TYPE9:   CLI
	 PUSH DS
	 PUSH DX
	 MOV  DX,0
	 PUSH DX
	 POP  DS
	 LEA  DX,MSG9
	 INT  10
	 POP  DX
	 POP  DS
	 STI
	 IRET

;
; INVALID INTERRUPT
;
INVALID: CLI
	 PUSH DS
	 PUSH DX
	 MOV  DX,0
	 PUSH DX
	 POP  DS
	 LEA  DX,MSGX
	 INT  10
	 POP  DX
	 POP  DS
	 STI
	 IRET


; PRINT STRING INTERRUPT  10H
;
; DX - ADDRESS OF STRING TO PRINT (MUST BE $ TERMINATED)
;
	 DOLLAR EQU 24
XPRINT:  PUSH DS
	 PUSH BP
	 PUSH DX
	 PUSH AX
	 MOV  BP,DX
	 MOV  DX,0
LOOP10:  MOV  AL,[BP]
	 CMP  AL,DOLLAR   ; CHECK FOR END OF STRING
	 JZ   ENDIT10
	 OUT  2,AL
	 INC  BP
	 JMP  LOOP10
ENDIT10: POP  AX
	 POP  DX
	 POP  BP
	 POP  DS
	 IRET

; READ STRING INTERRUPT   11H
;
; DX - BUFFER ADDRESS FOR STRING
; CX - MAXIMUM NUMBER OF CHARACTERS
; Returned in CX: number of chars read
; NOTE: STRING IS NOT $ TERMINATED
;
XREAD:   PUSH DS
	 PUSH BP
	 PUSH DX
	 PUSH AX
	 PUSH BX
	 MOV  BP,DX
	 MOV  DX,0
	 SUB  BX,BX
LOOP11:  IN   AL,1
	 OUT  2,AL    ;echo to screen (added by sschr354)
	 CMP  AL,CR      ;CHECK FOR CARRIAGE RETURN
	 JZ   ENDIT11
	 MOV  [BP],AL
	 INC  BX
	 INC  BP
	 LOOP LOOP11
ENDIT11: MOV  AL,LF
	 OUT  2,AL   ;output linefeed
	 MOV  CX,BX
	 POP  BX
	 POP  AX
	 POP  DX
	 POP  BP
	 POP  DS
	 IRET

; CONVERT STRING -&gt; INTEGER  INTERRUPT 12H
;
; DX - ADDRESS OF STRING ($ TERMINATED)
; CX - NUMBER OF CHARACTERS SCANNED
; AX - THE INTEGER
;
XDECI:   PUSH DS
	 PUSH BP
	 PUSH DX
	 PUSH BX
	 PUSH SI
	 PUSH DI
	 MOV  BP,DX
	 MOV  DX,0
	 SUB  BX,BX
	 SUB  AX,AX
	 SUB  CX,CX
	 SUB  SI,SI     ; USED TO FLAG START OF NUMBER IN STRING
	 SUB  DI,DI     ; USED TO TEST FOR ZERO
LOOP12:  MOV  AL,[BP]
	 INC  CX        ; COUNT NUMBER OF CHARACTERS PROCESSED
	 INC  BP        ; POINT TO NEXT CHARACTER IN STRING
	 CMP  AL,'0'
	 JL   SKIP12
	 CMP  AL,'9'
	 JG   SKIP12
	 MOV  SI,1      ; A NUMBER HAS BEEN FOUND
	 MOV  DX,%10
	 sub  ax,'0'     ; fix here by Michael Laird
	 push cx
	 mov  cx,ax  ;mov  tempnum,ax
	 mov  ax,bx
	 MUL  DX
	 mov  bx,ax
	 mov  ax,cx  ;mov  ax,tempnum
	 pop  cx
	 ADD  BX,AX
	 JMP  LOOP12
SKIP12:  CMP  SI,DI      ; CHECK FOR END OF NUMBER
	 JE   LOOP12
	 MOV  AX,BX
	 POP  DI         ; Fixed by Michael Laird and Phil Egly
	 POP  SI
	 POP  BX
	 POP  DX
	 POP  BP
	 POP  DS
	 IRET

; CONVERT INTEGER -&gt; STRING   INTERRUPT 13H
;
; DX - BUFFER ADDRESS FOR STRING
; AX - THE INTEGER
; CX - LENGTH OF STRING
; NOTE: STRING IS NOT $ TERMINATED
;
XDECO:   PUSH DS
	 PUSH BP
	 PUSH DX
	 PUSH BX
	 PUSH AX
	 MOV  BP,DX
	 MOV  DX,0
	 SUB  CX,CX
	 MOV  BX,%10
;
; PICK OFF EACH DIGIT FROM RIGHT TO LEFT AND CONVERT TO ASCII
; AND PUSH ON STACK (WE NEED TO REVERSE THE ORDER FOR THE STRING)
;
LOOP13:  SUB  DX,DX
	 DIV  BX
	 ADD  DL,'0'
	 PUSH DX
	 INC  CX        ; COUNT NUMBER OF CHARACTERS PROCESSED
	 CMP  AX,0
	 JNE  LOOP13
	 mov  bx,cx
;
; MOVE ASCII DIGITS FROM STACK TO STRING
;
POPLOOP: POP  DX
	 MOV  [BP],DL
	 INC  BP
	 LOOP POPLOOP
	 mov  cx,bx
	 POP  AX
	 POP  BX
	 POP  DX
	 POP  BP
	 POP  DS
	 IRET

; Add packed BCD
;
; SI - address of first BCD operand
; DI - address of second BCD operand
; BP - address of result
; CX - number of BCD bytes
;
BCDADD:  add si,cx
	 add di,cx
	 add bp,cx
	 clc
lop1:    mov al,[si]
	 adc al,[di]
	 daa
	 mov [bp],al
	 dec si
	 dec di
	 dec bp
	 loop lop1
	 iret

; Subtract packed BCD
;
; SI - address of first BCD operand
; DI - address of second BCD operand
; BP - address of result
; CX - number of BCD bytes
;
BCDSUB:  add si,cx
	 add di,cx
	 add bp,cx
	 clc
lop2:    mov al,[si]
	 sbb al,[di]
	 daa
	 mov [bp],al
	 dec si
	 dec di
	 dec bp
	 loop lop1
	 iret

; string -&gt; BCD
;enter:  si=addr of STR
;        di=addr to put BCD
;        cx=# bytes for BCD

BCDI:    push ax
	 push bx
	 push cx
	 push si
	 push dx
	 push bp
	 mov ax,0
	 mov bx,cx
	 mov cx,0
sbloop:  mov al,[si]
	 cmp al,' '
	 je getnext
	 cmp al,'9'
	 jg conv
	 cmp al,'0'
	 jl conv
	 jmp saveit
getnext: inc si
	 jmp sbloop
saveit:  inc cx
	 inc si
	 push ax
	 cmp cx,bx
	 je conv
	 jmp sbloop
conv:    cmp cx,0
	 jle pad
	 pop ax
	 sub al,'0'
	 mov bp,ax
	 dec cx
	 cmp cx,bx
	 je write
	 cmp cx,0
	 jle write
	 pop ax
	 sub al,'0'
	 mov dl,10
	 mul dl
	 add ax,bp
write:   dec bx
	 mov [di+bx],al
	 dec cx
	 cmp cx,0
	 jge conv
pad:     dec bx
	 mov byte [di+bx],0
	 cmp bx,0
	 jg pad
	 jl end
end:     pop bp
	 pop dx
	 pop si
	 pop cx
	 pop bx
	 pop ax
	 iret

; BCD -&gt; string
;enter:  si=addr of BCD (ff terminated)
;        di=addr to put STR (padded with blanks)
;        cx=max bytes for result

BCDO:    push ax
	 push bx
	 push si
	 push cx
	 push dx
	 mov bx,cx
	 mov cx,0
bsloop:  sub ax,ax
	 mov al,[si]
	 cmp cx,bx
	 je convert
	 cmp al,ff
	 jne putit
	 jmp convert
endit:   pop dx
	 pop cx
	 pop si
	 pop bx
	 pop ax
	 iret
putit:   inc cx
	 inc si
	 mov dl,10
	 div dl
	 push ax
	 jmp bsloop
convert: pop ax
	 add ah,'0'
	 dec bx
	 mov [di+bx],ah
	 add al,'0'
	 dec bx
	 mov [di+bx],al
	 loop convert
	 cmp bx,0
	 jl endit
padit:   dec bx
	 mov byte [di+bx],' '
	 cmp bx,0
	 jg padit
	 jmp endit

; write an integer in ax to stdout
;enter:  ax=integer value

WRITEINT: push cx
	 push dx
	 push bx
	 push si
	 mov  dx,sp
  sub sp,10
	 int 13
	 mov bx,dx
	 mov si,cx
	 mov byte ptr [bx+si],DOLLAR
	 int 10
  add sp,10
	 pop si
	 pop bx
	 pop dx
	 pop cx
	 iret

; writeln - output a CR/LF
;enter:  nothing

WRITELN: push ax
	 mov al,cr
	 out 2,al
	 mov al,lf
	 out 2,al
	 pop ax
	 iret

; read an integer from stdin and place in ax
;enter:   nothing
;leave:   ax=integer

READINT: push cx
	 push dx
	 push bx
	 push si
	 mov  dx,sp
  sub  sp,10
	 mov cx,6
	 int 11
	 mov bx,dx
	 mov si,cx
	 mov byte ptr [bx+si],DOLLAR
	 int 12
  add sp,10
	 pop si
	 pop bx
	 pop dx
	 pop cx
	 iret

; read until CR
;enter:  nothing

READLN: push ax
	 in al,1
	 cmp al,CR
	 jne READLN
	 pop ax
	 iret

