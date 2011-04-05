; SOURCE: D1E1.asm
; AUTHOR: Mr Wooster
; testing template for group 1 addressing modes and group 1 instructions


         SETREG    IP = 100
         ORG       100

;--------------------------------------------------------------------------------------
; group 1 instructions which use group 1 addressing modes: CBW, XCHG, HLT, INC, DEC
;--------------------------------------------------------------------------------------

; group 1 addressing mode: Acc (CBW)         

; group 1 addressing mode: AccReg (XCHG)

; group 1 addressing mode: None (HLT) - best to put this one at the end of the list! :-)

; group 1 addressing mode: Reg (INC, DEC)

; group 1 addressing mode: Seg (no group 1 instructions!)

; group 1 addressing mode: Unknown

;--------------------------------------------------------------------------------------
; group 2 addressing modes are used by these group 1 instructions: MOV, AND, JMP, LOOP
;--------------------------------------------------------------------------------------

; group 2 addressing mode: AccImm (MOV, AND) byte/word, direction

; group 2 addressing mode: AccMem (MOV) byte/word, direction

; group 2 addressing mode: Intra (JMP)

; group 2 addressing mode: RegImm (MOV)

; group 2 addressing mode: Short (LOOP, JMP)



         HLT
;--------------------------------------------------------------------------------------
; put your data/variables here using DB and/or DW commands
;--------------------------------------------------------------------------------------
