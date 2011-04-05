; SOURCE: test5.asm
; AUTHOR: George Zimmer
;
; simulates a user logging on to a bulletin board

      SETREG IP=BEGIN ;* register IP will be set to address of BEGIN *
      SETREG SP = 5fff; * put our top of stack at 7f00h
      ORG %1024             ;* START ASSEMBLY AT 400h
      CR EQU %13    ;* EQU defines a constant ( like #define in C )
      LF EQU %10
      INCLUDE IO.ASM ;* Assembles IO.ASM at THIS location, thats why
BEGIN:
      MOV AX,OFFSET TEXT
      PUSH AX
      CALL PRINT
      MOV AX,OFFSET PROMPT1  ;* "OFFSET" tells assembler to use IMMEDIATE mode,
      PUSH AX
      CALL PRINT
      MOV AX,OFFSET NAME
      PUSH AX
      CALL INPUT
START:
      MOV AX,OFFSET PROMPT2
      PUSH AX
      CALL PRINT
      MOV AX,OFFSET BUFFER;
      PUSH AX
      CALL INPUT

      MOV CX,OFFSET LAST_CHR -PASSWORD  ;* Assembler performs (+) and (-)...
      MOV SI,OFFSET PASSWORD            ;but NOT multiplication or division!
      MOV DI,OFFSET BUFFER
COMPARE:
      MOV AL,[SI]
      CMP AL,[DI]
      JNE NO_GOOD
      INC SI
      INC DI
      LOOP COMPARE
      MOV AX,OFFSET ACCESS
      PUSH AX
      CALL PRINT
      MOV AX,OFFSET BBSTXT
      PUSH AX
      CALL PRINT
      HLT
NO_GOOD:
      MOV AX,OFFSET DENIED
      PUSH AX
      CALL PRINT
      JMP START
BUFFER:     DB BLOCK %80 { 0 } ;* creates a block of 80 zero's *
PROMPT1:    DB LF,CR,"Please enter your REAL name :",0
PROMPT2:    DB LF,CR,"Enter password:",0
TEXT:       DB "ATZ",LF,CR,"ATDP 233-8559",LF,CR,"RINGING",BLOCK 8 {". "},LF,CR
	    DB LF,CR,"CONNECT 300",CR,"Welcome to MYBBS",LF,CR,0
ACCESS:     DB LF,CR,LF,CR,"Welcome back, " ;* no zero here so we can print name too.*
NAME:       DB BLOCK %30 {0}
BBSTXT:     DB LF,CR,LF,CR,BLOCK 0A { '*','-' },"< Main Menu >", BLOCK 0A { '-','*' },LF,CR,LF,CR
	    DB "F>iles                    G>oodbye",LF,CR
	    DB "M>ail                     D>oors",LF,CR
	    DB "U>tilities                B>ulletins",LF,CR,LF,CR
	    DB %172,%237,%205,%171,%32,"NO CARRIER",LF,CR,LF,CR,0
DENIED:     DB LF,CR,"Incorrect password",0
PASSWORD:   DB "password"
LAST_CHR:   DB 0     ;* LAST_CHR is used to find length of password *
