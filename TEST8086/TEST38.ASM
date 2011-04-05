; PROGRAM     : TEST38.ASM
; AUTHOR      : Peter M. Schroeder
; ASSEMBLED   : 12-07-91
;
; Reads in a decimal number, converts it to binary, and demonstrates rolls and
; shifts on it.
;

SETREG IP = BEGIN
SETREG SP = 5FFF

EOS       EQU   24                  ; End-of-string
CRTN      EQU   D                   ; Carriage-return
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
CONTINUE: LEA   DI,RESPONSE         ; Set index to point to string area
          CLC                       ; Clear carry flag
          LEA   DX,MESS0            ; Original:
          INT   10
          CALL  TOBIN

          LEA   DX,MESS1            ; After RCL:
          INT   10
          RCL   AX,1
          CALL  TOBIN
          LEA   DX,MESS2            ; After RCR:
          INT   10
          RCR   AX,1
          CALL  TOBIN

          LEA   DX,MESS3            ; After ROL:
          INT   10
          ROL   AX,1
          CALL  TOBIN

          LEA   DX,MESS4            ; After ROR:
          INT   10
          ROR   AX,1
          CALL  TOBIN

          LEA   DX,MESS5            ; After SHL:
          INT   10
          SHL   AX,1
          CALL  TOBIN

          LEA   DX,MESS6            ; After SAR:
          INT   10
          SAR   AX,1
          CALL  TOBIN

          LEA   DX,MESS7            ; After SHR:
          INT   10
          SHR   AX,1
          CALL  TOBIN

          JMP   AGAIN               ; Loop back for another number
EXIT:     LEA   DX,GOODBYE          ; Display the goodbye message:
          INT   10
          HLT                       ; Halt the program

TOBIN: pushf
          PUSH  DX                  ; Save registers:
          PUSH  AX
          PUSH  BX
          PUSH  CX
          PUSH  DI
          PUSH  SI
          MOV   BX,2                ; Base = 2
          MOV   CX,10               ; Minimum length (16)
          XOR   SI, SI              ; Set digit-count to 0
          JCXZ  TB2                 ; If CX = 0, set it to 1
TB1:      XOR   DX,DX               ; Extend AX to 32-bits
          DIV   BX                  ; AX <- AXDX div BX; DX <- remainder
          OR    DL,'0'              ; Convert to ASCII "0" or "1"
          PUSH  DX                  ; Save digit on stack
          INC   SI                  ; Count digits on stack
          LOOP  TB1                 ; Loop on minimum digit count
TB2:      INC   CX                  ; Set CX = 1 in case not done
          OR    AX,AX               ; Is AX = 0? (all digits done)
          JNZ   TB1                 ; No, so continue conversion
          MOV   CX,SI               ; Set CX to # of digits on stack
          JCXZ  TB4                 ; Skip next loop if there are none
TB3:      POP   AX                  ; Pop next digit off of stack
          MOV   [DI],AL             ; Store into string-buffer
          INC   DI                  ; Advance DI
          LOOP  TB3                 ; Loop for # of digits in CX
TB4:      MOV   [DI], BYTE EOS      ; Store "$" at end-of-string
          LEA   DX,RESPONSE         ; Display the result:
          INT   10
          POP   SI                  ; Restore the saved registers:
          POP   DI
          POP   CX
          POP   BX
          POP   AX
          POP   DX
          popf
          RET                       ; Return

TITLE:    DB    CRTN,LF,C9,BLOCK 11 {CD},BB,CRTN,LF,BA
          DB    " Roll/Shift Demo ",BA,CRTN,LF,C8,BLOCK 11 {CD},BC
          DB    CRTN,LF,"by: Peter Schroeder",CRTN,LF,EOS
PROMPT:   DB    CRTN,LF,CRTN,LF
          DB    "Decimal value to work with (press <ENTER> to quit)? ",EOS
ERROR:    DB    CRTN,LF,7,"**ERROR**  Illegal character in string",EOS
MESS0:    DB    CRTN,LF,"Original.... : ",EOS
MESS1:    DB    CRTN,LF,"After RCL... : ",EOS
MESS2:    DB    CRTN,LF,"After RCR... : ",EOS
MESS3:    DB    CRTN,LF,"After ROL... : ",EOS
MESS4:    DB    CRTN,LF,"After ROR... : ",EOS
MESS5:    DB    CRTN,LF,"After SHL... : ",EOS
MESS6:    DB    CRTN,LF,"After SAR... : ",EOS
MESS7:    DB    CRTN,LF,"After SHR... : ",EOS
GOODBYE:  DB    CRTN,LF,"Goodbye!!!"
NEWLINE:  DB    CRTN,LF,EOS
RESPONSE: DB    BLOCK 11 {' '}
          DW    0