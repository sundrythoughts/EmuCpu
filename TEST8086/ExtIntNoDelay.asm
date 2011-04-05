;
; EXTINT.ASM
; TESTS EXT INTERRUPTS
; BY DANIEL SUMLIN 2000
;
         SETREG IP=MAIN
         SETREG SP=0100
         ORG 1000
         
MSG:     DB "Interrupts disabled$"
MSG2:    DB "Interrupts enabled$"
         
MAIN:    STI
         MOV CX, 80
         LEA DX, MSG2
LOOP1:   INT 10
         LOOP LOOP1
         CLI
         LEA DX, MSG
         MOV CX, 80
LOOP2:   INT 10
         LOOP LOOP2
         HLT
