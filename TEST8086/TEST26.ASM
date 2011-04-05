; SOURCE: test26.asm
; AUTHOR: Phil Egly
;
; play simulated four voice music

       SETREG IP = BEGIN
       SETREG SP = 5FFF
       SETREG BX = 0030
       CR EQU %13
       LF EQU %10
       ORG 100
;NOTEC1: DW %65
;NOTED1: DW %73
;NOTEE1: DW %82
;NOTEF1: DW %87
;NOTEG1: DW %98
NOTEA1: DW %110
NOTEB1F: DW %118
NOTEB1: DW %124
NOTEC2: DW %130
NOTED2: DW %146
NOTEE2F: DW %155
NOTEE2: DW %164
NOTEF2: DW %174
NOTEG2: DW %196
NOTEA2: DW %220
NOTEB2F: DW %233
NOTEB2: DW %246
NOTEC3: DW %261
NOTED3: DW %293
NOTEE3F: DW %312
NOTEE3: DW %330
NOTEF3: DW %349
NOTEG3: DW %392
NOTEA3: DW %440
NOTEB3F: DW %467
NOTEB3: DW %493
NOTEC4: DW %523
NOTED4: DW %587
;NOTEE4F: DW %623
;NOTEE4: DW %659
;NOTEF4: DW %698
;NOTEG4: DW %784
;NOTEA4: DW %880
;NOTEB4F: DW %934
;NOTEB4: DW %988
;NOTEC5: DW %1047
;NOTED5: DW %1175
;NOTEE5: DW %1319
;NOTEF5: DW %1397
;NOTEG5: DW %1568
;NOTEA5: DW %1760
;NOTEB5F: DW %1868
;NOTEB5: DW %1976
;NOTEC6: DW %2094
HEADR1:  DB "Simulated 4-Voice Music by Phil Egly",CR,LF,LF,"$"
HEADR2:  DB "It came upon the midnight clear,",CR,LF,"$"
HEADR3:  DB "that glorious song of old,",CR,LF,"$"
HEADR4:  DB "from angels bending near the earth,",CR,LF,"$"
HEADR5:  DB "to touch their harps of gold.",CR,LF,"$"
BEGIN:  LEA DX,HEADR1
        INT 10
        LEA DX,HEADR2
        INT 10
        LEA DX,HEADR3
        INT 10
        LEA DX,HEADR4
        INT 10
        LEA DX,HEADR5
        INT 10
        MOV DX,0001
BEGINB: MOV AX,NOTEB1F
       MOV CX,1000
       OUT 03,AL
       MOV AX,NOTEF2
       OUT 03,AL
       MOV AX,NOTED3
       OUT 03,AL
       MOV AX,NOTEF3
       OUT 03,AL

       MOV AX,NOTEB1F
       OUT 03,AL
       MOV AX,NOTEF2
       OUT 03,AL
       MOV AX,NOTED3
       OUT 03,AL
       MOV AX,NOTED4
       OUT 03,AL

       MOV AX,NOTEB1F
       OUT 03,AL
       MOV AX,NOTEF2
       OUT 03,AL
       MOV AX,NOTED3
       OUT 03,AL
       MOV AX,NOTED4
       OUT 03,AL

       MOV AX,NOTEB1F
       OUT 03,AL
       MOV AX,0185
       OUT 03,AL
       MOV AX,NOTED3
       OUT 03,AL
       MOV AX,NOTEC4
       OUT 03,AL

       MOV AX,NOTEB1F
       OUT 03,AL
       MOV AX,NOTEG2
       OUT 03,AL
       MOV AX,NOTEE3F
       OUT 03,AL
       MOV AX,NOTEC4
       OUT 03,AL

       MOV AX,NOTEB1F
       OUT 03,AL
       MOV AX,NOTEG2
       OUT 03,AL
       MOV AX,NOTEE3F
       OUT 03,AL
       MOV AX,NOTEB3F
       OUT 03,AL

       MOV AX,NOTEB1F
       OUT 03,AL
       MOV AX,NOTEA2
       OUT 03,AL
       MOV AX,NOTEE3F
       OUT 03,AL
       MOV AX,NOTEG3
       OUT 03,AL

       MOV AX,NOTEB1F
       OUT 03,AL
       MOV AX,NOTEB2F
       OUT 03,AL
       MOV AX,NOTED3
       OUT 03,AL
       MOV AX,NOTEF3
       OUT 03,AL

       MOV AX,NOTEB1F
       OUT 03,AL
       MOV AX,NOTEB2F
       OUT 03,AL
       MOV AX,NOTED3
       OUT 03,AL
       MOV AX,NOTEF3
       OUT 03,AL

       MOV AX,NOTEA1
       OUT 03,AL
       MOV AX,NOTEF2
       OUT 03,AL
       MOV AX,NOTEE3F
       OUT 03,AL
       MOV AX,NOTEG3
       OUT 03,AL

       MOV AX,NOTEB1F
       OUT 03,AL
       MOV AX,NOTEF2
       OUT 03,AL
       MOV AX,NOTED3
       OUT 03,AL
       MOV AX,NOTEF3
       OUT 03,AL

       MOV AX,NOTEB1F
       OUT 03,AL
       MOV AX,NOTEF2
       OUT 03,AL
       MOV AX,NOTED3
       OUT 03,AL
       MOV AX,NOTEF3
       OUT 03,AL

       MOV AX,NOTEB1F
       OUT 03,AL
       MOV AX,NOTEB2F
       OUT 03,AL
       MOV AX,NOTED3
       OUT 03,AL
       MOV AX,NOTEF3
       OUT 03,AL

       CMP DL,02
       JNE NEXTT
       JMP SECND
NEXTT: INC DX

       MOV AX,NOTEE2F
       OUT 03,AL
       MOV AX,NOTEB2F
       OUT 03,AL            ;Glo
       MOV AX,NOTEE3F
       OUT 03,AL
       MOV AX,NOTEG3
       OUT 03,AL

       MOV AX,NOTEF2
       OUT 03,AL
       MOV AX,NOTEB2F
       OUT 03,AL           ;-or-
       MOV AX,NOTEE3F
       OUT 03,AL
       MOV AX,NOTEA3
       OUT 03,AL

       MOV AX,NOTEG2
       OUT 03,AL
       MOV AX,NOTEB2F
       OUT 03,AL          ;-rious
       MOV AX,NOTEE3F
       OUT 03,AL
       MOV AX,NOTEB3F
       OUT 03,AL

       MOV AX,NOTEG2
       OUT 03,AL
       MOV AX,NOTEB2F
       OUT 03,AL          ;So-
       MOV AX,NOTEE3
       OUT 03,AL
       MOV AX,NOTEB3F
       OUT 03,AL

       MOV AX,NOTEG2
       OUT 03,AL
       MOV AX,NOTEB2F
       OUT 03,AL           ;-ng
       MOV AX,NOTEE3
       OUT 03,AL
       MOV AX,NOTEC4
       OUT 03,AL

       MOV AX,NOTEC2
       OUT 03,AL
       MOV AX,NOTEB2F
       OUT 03,AL           ;of
       MOV AX,NOTEE3
       OUT 03,AL
       MOV AX,NOTED4
       OUT 03,AL

       MOV CX,0005
       PUSH DX
OLD1:  MOV DX,CX
       MOV CX,1000
       MOV AX,NOTEF2
       OUT 03,AL
       MOV AX,NOTEA2
       OUT 03,AL        ;Old
       MOV AX,NOTEF3
       OUT 03,AL
       MOV AX,NOTEC4
       OUT 03,AL
       MOV CX,DX
       LOOP OLD1
       POP DX
       JMP BEGINB

SECND: MOV AX,NOTEE2F
       OUT 03,AL
       MOV AX,NOTEB2F
       OUT 03,AL            ;to-
       MOV AX,NOTEE3F
       OUT 03,AL
       MOV AX,NOTEG3
       OUT 03,AL

       MOV AX,NOTEE2F
       OUT 03,AL
       MOV AX,NOTEB2F
       OUT 03,AL            ;-uch
       MOV AX,NOTEE3F
       OUT 03,AL
       MOV AX,NOTEG3
       OUT 03,AL

       MOV AX,NOTEC2
       OUT 03,AL
       MOV AX,NOTEC3
       OUT 03,AL            ;their
       MOV AX,NOTEE3F
       OUT 03,AL
       MOV AX,NOTEG3
       OUT 03,AL

       MOV AX,NOTEF2
       OUT 03,AL
       MOV AX,NOTEC3
       OUT 03,AL            ;Har-
       MOV AX,NOTEE3F
       OUT 03,AL
       MOV AX,NOTEA3
       OUT 03,AL

       MOV AX,NOTEF2
       OUT 03,AL
       MOV AX,NOTEB3F
       OUT 03,AL            ;-rps
       MOV AX,NOTEE3F
       OUT 03,AL
       MOV AX,NOTEG3
       OUT 03,AL

       MOV AX,NOTEF2
       OUT 03,AL
       MOV AX,NOTEA2
       OUT 03,AL            ;of
       MOV AX,NOTEE3F
       OUT 03,AL
       MOV AX,NOTEF3
       OUT 03,AL

       MOV CX,0005
GOLD:  MOV DX,CX
       MOV CX,1000
       MOV AX,NOTEB1F
       OUT 03,AL
       MOV AX,NOTEB2F
       OUT 03,AL           ;Gold
       MOV AX,NOTED3
       OUT 03,AL
       MOV AX,NOTEB3F
       OUT 03,AL
       MOV CX,DX
       LOOP GOLD
       HLT
