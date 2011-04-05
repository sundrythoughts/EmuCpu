; PROGRAM     : TEST39.ASM
; AUTHOR      : Peter M. Schroeder
; ASSEMBLED   : 12-07-91
;
; Allows the user to input a string and then checks to see if it is a
; palindrome.  Also checks to see if any "Z"s or "z"s are in the original
; string.  Demonstrates the use of the STRING instructions LODS, STOS, CMPS,
; and SCAS, as well as many other instructions.
;

SETREG IP = BEGIN
SETREG SP = 5FFF
SETREG DS = 0000
SETREG ES = 0000

EOS       EQU   24                  ; End-of-string
CRTN      EQU   D                   ; Carriage-return
LF        EQU   A                   ; Line-feed

ORG 1000

EXIT:     LEA   DX,GOODBYE          ; Display the goodbye message:
          INT   10
          HLT                       ; Halt the program
BEGIN:    STI                       ; Allow for interrupts
          LEA   DX,TITLE            ; Display title of program:
          INT   10
AGAIN:    LEA   DX, PROMPT          ; Display prompt:
          INT   10
          LEA   DX,RESPONSE         ; Read in a response:
          MOV   CX,%39
          INT   11
          MOV   BX,CX
          MOV   RESPONSE[BX],BYTE '$'
          LEA   DX,NEWLINE          ; Skip down a line
          INT   10
          JCXZ  EXIT                ; If length on response is 0 then exit
          LEA   SI,RESPONSE
          ADD   SI,BX               ; Set SI to end of read-in string
          DEC   SI
          LEA   DI,COPY             ; Set DI to beginning of copy block
LOOP:     STD                       ; Set direction to auto-decrement
          LODSB                     ; Load the byte at SI into AL; decrement SI
          CLD                       ; Set direction to auto-increment
          STOSB                     ; Store the byte in AL at DI; advance DI
          DEC   BX                  ; Decrement BX
          JNZ   LOOP                ; If not zero then keep copying
          LEA   SI,RESPONSE         ; Set SI to beginning of read-in string
          LEA   DI,COPY             ; Set DI to beginning of reversed copy
          MOV   BX,CX               ; Save CX in BX
          REPE  CMPSB               ; Compare the strings
          JNE   NOTEQUAL            ; The strings are not equal (CX <> 0)
          LEA   DX,MSG1             ; Print out the palindrome message:
          INT   10
          MOV   DX,1                ; Store a 1 on the stack
          PUSH  DX
          JMP   CHECKZ
NOTEQUAL: LEA   DX,MSG2             ; Print out the not-a-palindrome message:
          INT   10
          XOR   DX,DX               ; Store a 0 on the stack
          PUSH  DX
CHECKZ:   MOV   CX,BX               ; Restore CX from BX
          LEA   DI,RESPONSE         ; Set DI to beginning of read-in string
          MOV   AL,'Z'              ; Put a "Z" in AL
          REPNE SCASB               ; Scan the string for a "Z"
          JNE   ZNO                 ; A "Z" was not found (CX <> 0)
ZYES:     MOV   CX,1                ; Compare the top-of-stack to a 1:
          POP   DX
          CMP   CX,DX
          JNE   CONJBY
          LEA   DX,CONJA            ; Equal, so the conjunction to use is "and"
          INT   10
          JMP   ZYES2
CONJBY:   LEA   DX,CONJB            ; Use the conjunction "but"
          INT   10
ZYES2:    LEA   DX,MSG3             ; Print out the Z's message:
          INT   10
          JMP   AGAIN               ; Loop back for another string
ZNO:      XCHG  CX,BX               ; Restore CX by exchanging with BX
          LEA   DI,RESPONSE         ; Set DI to beginning of read-in string
          MOV   AL,7A               ; Put a "z" in AL
          REPNE SCASB               ; Scan the string for a "z"
          JE    ZYES                ; A "z" was found (CX = 0)
          XOR   CX,CX               ; Compare the top-of-stack to a 0:
          POP   DX
          CMP   CX,DX
          JNE   CONJBN
          LEA   DX,CONJA            ; Equal, so the conjunction to use is "and"
          INT   10
          JMP   ZNO2
CONJBN:   LEA   DX,CONJB            ; Use the conjunction "but"
          INT   10
ZNO2:     LEA   DX,MSG4             ; Print out the no-Z's message:
          INT   10
          JMP   AGAIN               ; Loop back for another string

TITLE:    DB    CRTN,LF,C9,BLOCK 14 {CD},BB,CRTN,LF,BA
          DB    " Palindrome Checker ",BA,CRTN,LF,C8,BLOCK 14 {CD},BC
          DB    CRTN,LF,"  by Peter Schroeder",CRTN,LF,CRTN,LF
          DB    "(Also checks for the presence of Z's and z's)",CRTN,LF
          DB    "Note that the checker IS case-sensitive!",CRTN,LF,EOS
PROMPT:   DB    CRTN,LF,CRTN,LF
          DB    "Enter a string (press <ENTER> to quit)? ",EOS
MSG1:     DB    CRTN,LF,"This string IS a palindrome,",EOS
MSG2:     DB    CRTN,LF,"This string is NOT a palindrome,",EOS
MSG3:     DB    " you used at least one Z (or z)!",EOS
MSG4:     DB    " you did not use any Z's (or z's).",EOS
CONJA:    DB    CRTN,LF,"and",EOS
CONJB:    DB    CRTN,LF,"but",EOS
GOODBYE:  DB    CRTN,LF,"Goodbye!!!"
NEWLINE:  DB    CRTN,LF,EOS
RESPONSE: DB    BLOCK %40 {' '}
COPY:     DB    BLOCK %40 {' '}
          DW    0