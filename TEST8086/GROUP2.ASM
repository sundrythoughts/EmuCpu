;
; GROUP2.ASM
; TESTS THE BASIC EXECUTION OF GROUP II INSTRUCTIONS
; BY Dan Wooster
;
         SETREG IP=MAIN
         SETREG SP=0100
         ORG 1000
;
; TESTS simple ADD instructions
;
MAIN:    MOV AX,10
         ADD AX,30
         SUB AX,AX     ; SHOULD ZERO OUT AX
         MOV AL,10
         ADD AL,30
         MOV AH,50
         ADD AH,AL

; TEST CONDITION CODE SETTINGS FOR ADD
;
;                        RESULT   OVER  SIGN  ZERO  AUXCAR  CARRY PARITY
;                        ------   ----  ----  ----  ------  ----- ------
         MOV AX,FFFF
         ADD AX,1      ;  0000      0     0     1      1      1      1
         MOV AX,7FFF
         ADD AX,7FFF   ;  FFFE      1     1     0      1      0      0
         MOV AX,1
         ADD AX,FFFE   ;  FFFF      0     1     0      0      0      1
         MOV AX,0
         MOV AL,7F
         ADD AL,7F     ;  00FE      1     1     0      1      0      0
         MOV AX,8000
         ADD AX,8000   ;  0000      1     0     1      0      1      1
         MOV AX,8000
         ADD AX,7FFF   ;  FFFF      0     1     0      0      0      1

; TEST ADC
;
         MOV AX,0
         STC
         ADC AX,0      ;  0001
;
; TESTS simple SUB instructions
;
         MOV AX,30
         SUB AX,10
         SUB AX,AX
         MOV AL,30
         SUB AL,10
         MOV AH,50
         ADD AL,AH

; TEST CONDITION CODE SETTINGS FOR SUB
;
;                        RESULT   OVER  SIGN  ZERO  AUXCAR  CARRY PARITY
;                        ------   ----  ----  ----  ------  ----- ------
         MOV AX,FFFF
         SUB AX,1      ;  FFFE      0     1     0      0      0      0
         MOV AX,FFFF
         SUB AX,FFFF   ;  0000      0     0     1      0      0      1
         MOV AL,FF
         MOV AH,7F
         SUB AH,7F     ;  00FF

; TEST SBB
;
         MOV AX,0
         STC
         SBB AX,0      ;  FFFF

; TEST INC AND DEC
;
         MOV AX,1234
         INC AX
         DEC AX
         MOV AX,0
         DEC AX
         MOV AX,1234
         INC AL
         INC AH
         DEC AL
         DEC AH

; MAKE SURE INC/DEC DON'T AFFECT CARRY FLAG
;
         STC
         DEC AX
         INC AL

;
; TESTS CMP INSTRUCTIONS
;
;                              OVER  SIGN  ZERO  AUX  CARRY
;                              ----  ----  ----  ---  -----
         MOV AX,1234
         MOV BX,FFFF
         MOV CX,5599
         CMP AX,BX        ;       0     0     0    1      1
         CMP AH,AL        ;       0     1     0    1      1
         CMP AL,AH        ;       0     0     0    0      0
         CMP AX,DATA1     ;       0     0     0    1      1
         CMP BX,0         ;       0     1     0    0      0
         CMP BX,CX        ;       0     1     0    0      0
         CMP CH,CL        ;       1     1     0    1      1
         CMP CL,CH        ;       1     0     0    0      0
         CMP AX,1234      ;       0     0     1    0      0
         CMP BX,FFFF      ;       0     0     1    0      0
         CMP CL,99        ;       0     0     1    0      0

; TEST MUL
;
;                        RESULT   OVER  CARRY
;                        ------   ----  -----
         MOV AX,0
         MOV AL,7F
         MOV CL,2
         MUL CL        ; 00FE       0     0
         MOV AX,0
         MOV AL,7F
         MOV CH,7F
         MUL CH        ; 3F01       1     1
         MOV AX,7FFF
         MOV BX,2
         MUL BX        ; FFFE       0     0
         MOV AX,7FFF
         MOV BX,7FFF
         MUL BX        ; 0001:3FFF  1     1

; TEST DIV
;
;                        RESULT
;                        ------
         MOV DX,0
         MOV AX,1000
         MOV CX,5
         DIV CX        ; 0333:0001
         MOV AX,0010
         MOV CH,3
         DIV CH        ; 0105


; TEST FOR DIVIDE OVERFLOW

         MOV AX,1000
         MOV CH,5
         DIV CH

; TEST NEG AND CBW
;
         MOV AX,FFFF
         NEG AX           ; 0001
         MOV AX,00FF
         CBW              ; FFFF
         HLT
DATA1:   DW ABCD
DATA2:   DW DEF0

