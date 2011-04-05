;
; TEMPLATE.ASM
; 
         CR EQU %13      ; carriage return character
         LF EQU %10      ; line feed character     
         SETREG IP=MAIN
         SETREG SP=5FFF
         ORG 1000
;
; define your variable here
;
INTROMSG:     DW "PROGRAM NAME",CR,LF,"$"
PROMPTMSG:    DW "INPUT PROMPT: ","$"
WORDVAR:      DW 0
BYTEVAR:      DB 0

;
; define your subroutines here; don't forget to push the registers you use onto the stack 1st!
;
SUB:     PUSH AX
         PUSH BX

         POP BX
         POP AX
         RET

;
; main program begins here; first instruction MUST start on the next line
MAIN:    

         HLT
