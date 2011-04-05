;
; XLAT.ASM
; requires lea,in,out,and xlat (and hlt)
;
; reg checksum: 392
; RAM checksum: 536,851,316
;
; and i had to hand assemble it, too.
;
      SETREG IP=MAIN
      SETREG BX=0221
      SETREG SP=0100
      ORG 1000

MAIN:  LEA DX,MSG
       INT 10
       LEA BX,DATA1
START: IN  AL,01
       CMP AL,1B
       JE  DONE
       XLAT
       OUT 02,AL
       JMP START
DONE:  HLT

DATA1: DB BLOCK %128 { 0 }
MSG:   DB "XLAT test",d,a
       DB "every key should be output",d,a
       DB "as though shift were pressed.",d,a,
       DB "press ESC to quit",d,a,d,a
       DB "$"
       
       
      ; these had to be added by hand on top
      ; of the space reserved above.
      ;
      ; DB "..........",A,"..",D,".................. 1",27,"3457",22,"908=<_>?)!@#$%^&*(;:,+./2abcdefghijklmnopqrstuvwxyz{|}6-~ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]`."
