; PROGRAM     : TESTRTN1.ASM
; AUTHOR      : Peter M. Schroeder
; ASSEMBLED   : 12-07-91
;
; Reads in a decimal number and converts it to binary, hexadecimal, and
; signed and unsigned decimal.
;

SETREG IP = BEGIN
SETREG SP = 5FFF

EOS       EQU   24                  ; End-of-string
CR        EQU   D                   ; Carriage-return
LF        EQU   A                   ; Line-feed

ORG 1000

BEGIN:    STI                       ; Allow for interrupts
          LEA   DX,TITLE            ; Display title of program:
          INT   10
AGAIN:    LEA   DX, PROMPT          ; Display prompt:
          INT   10
          LEA   DX,RESPONSE         ; Read in a response:
          MOV   CX,10
          INT   11
          MOV   BX,CX
          MOV   RESPONSE[BX],BYTE '$'
          LEA   DX,NEWLINE          ; Skip down a line
          INT   10
          JCXZ  EXIT                ; If length on response is 0 then exit
          LEA   DX,RESPONSE         ; Convert response to integer in AX:
          INT   12
          DEC   CX
          CMP   BX,CX               ; Check for invalid characters:
          JE    CHECKNEG
          LEA   DX,ERROR            ; Display the error message:
          INT   10
          JMP   AGAIN
CHECKNEG: CMP   [RESPONSE],BYTE '-' ; Check if the number should be negative:
          JNE   CONTINUE
          NEG   AX                  ; Make it negative (INT 12 doesn't do this)
CONTINUE: LEA   DX,BINARY           ; Binary:
          INT   10                  ;   display the message
          MOV   CX,10               ;   minimum length
          LEA   DI,RESPONSE         ;   convert:
          CALL  TOASCBIN
          LEA   DX,RESPONSE         ;   display the result:
          INT   10
          LEA   DX,HEXA             ; Hexadecimal:
          INT   10                  ;   display the message
          MOV   CX,4                ;   minimum length
          LEA   DI,RESPONSE         ;   convert:
          CALL  TOASCHEX
          LEA   DX,RESPONSE         ;   display the result:
          INT   10
          LEA   DX,DECIMAL          ; Unsigned decimal:
          INT   10                  ;   display the message
          MOV   CX,1                ;   minimum length
          LEA   DI,RESPONSE         ;   convert:
          CALL  TOASCDEC
          LEA   DX,RESPONSE         ;   display the result:
          INT   10
          LEA   DX,SDECI            ; Signed decimal:
          INT   10                  ;   display the message
          MOV   CX,1                ;   minimum length
          LEA   DI,RESPONSE         ;   convert:
          CALL  TOASCSGN
          LEA   DX,RESPONSE         ;   display the result:
          INT   10
          JMP   AGAIN               ; Loop back for another number
EXIT:     LEA   DX,GOODBYE          ; Display the goodbye message:
          INT   10
          HLT                       ; Halt the program

TOASCBIN: PUSH  BX                  ; Save register:
          MOV   BX,2                ; Set the base (2)
          CALL  TOASCII             ; Do the conversion
          POP   BX                  ; Restore the saved register:
          RET                       ; Return

TOASCHEX: PUSH  BX                  ; Save register:
          MOV   BX,10               ; Set the base (16)
          CALL  TOASCII             ; Do the conversion
          POP   BX                  ; Restore the saved register:
          RET                       ; Return

TOASCDEC: PUSH  BX                  ; Save register:
          MOV   BX,A                ; Set the base (10)
          CALL  TOASCII             ; Do the conversion
          POP   BX                  ; Restore the saved register:
          RET                       ; Return

TOASCSGN: PUSH  BX                  ; Save registers:
          PUSH  DI
          CMP   AX,0                ; Is the signed number less than zero?
          JGE   GT0
          NEG   AX                  ; Yes, make it positive
          MOV   [DI], BYTE '-'      ;  and insert a negative sign in the result:
          INC   DI
GT0:      MOV   BX,A                ; Set the base (10)
          CALL  TOASCII             ; Do the conversion
          POP   DI                  ; Restore the saved registers:
          POP   BX
          RET                       ; Return

TOASCII:  PUSH  DX                  ; Save registers:
          PUSH  AX
          PUSH  CX
          PUSH  DI
          PUSH  SI
          XOR   SI, SI              ; Set digit-count to 0
          JCXZ  TA2                 ; If CX = 0, set it to 1
TA1:      XOR   DX,DX               ; Extend AX to 32-bits
          DIV   BX                  ; AX <- AXDX div BX; DX <- remainder
          CALL  HEXDIGIT            ; Convert to ASCII digit
          PUSH  DX                  ; Save digit on stack
          INC   SI                  ; Count digits on stack
          LOOP  TA1                 ; Loop on minimum digit count
TA2:      INC   CX                  ; Set CX = 1 in case not done
          OR    AX,AX               ; Is AX = 0? (all digits done)
          JNZ   TA1                 ; No, so continue conversion
          MOV   CX,SI               ; Set CX to # of digits on stack
          JCXZ  TA4                 ; Skip next loop if there are none
TA3:      POP   AX                  ; Pop next digit off of stack
          MOV   [DI],AL             ; Store into string-buffer
          INC   DI                  ; Advance DI
          LOOP  TA3                 ; Loop for # of digits in CX
TA4:      MOV   [DI], BYTE EOS      ; Store "$" at end-of-string
          POP   SI                  ; Restore the saved registers:
          POP   DI
          POP   CX
          POP   AX
          POP   DX
          RET                       ; Return

HEXDIGIT: CMP   DL,A                ; Is dl < hex "A"?
          JB    LT10                ; Yes
          ADD   DL,37               ; No, convert to ASCII "A" through "F"
          JMP   HDRET
LT10:     OR    DL,'0'              ; Convert to ASCII "0" through "9"
HDRET:    RET                       ; Return

TITLE:    DB    CR,LF,C9,BLOCK 13 {CD},BB,CR,LF,BA
          DB    " Decimal Convertor ",BA,CR,LF,C8,BLOCK 13 {CD},BC
          DB    CR,LF," by Peter Schroeder",CR,LF,EOS
PROMPT:   DB    CR,LF,CR,LF,"Decimal value to convert (press <ENTER> to quit)? ",EOS
ERROR:    DB    CR,LF,7,"**ERROR**  Illegal character in string",EOS
BINARY:   DB    CR,LF,"Binary.............. : ",EOS
HEXA:     DB    CR,LF,"Hexadecimal......... : ",EOS
DECIMAL:  DB    CR,LF,"Unsigned decimal.... : ",EOS
SDECI:    DB    CR,LF,"Signed decimal...... : ",EOS
GOODBYE:  DB    CR,LF,"Goodbye!!!"
NEWLINE:  DB    CR,LF,EOS
RESPONSE: DB    BLOCK 11 {' '}
          DW    0