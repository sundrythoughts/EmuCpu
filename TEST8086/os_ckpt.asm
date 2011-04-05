; Sim86OS Demo Program
; by Jordan Jueckstock
; 11/20/2007
;----------------------
; Reads a CR/LF-terminated line from STDIN
; and parses a sequence of white-space-delimited
; positive integers; finds and prints the maximum.

; Constants for Sim86OS "system calls"
;--------------------------------------
read_str  EQU 11
write_str EQU 10
atoi      EQU 12
itoa      EQU 13

; Other constants
;-----------------
CR EQU 0A
LF EQU 0D

; Header/Setup
;--------------
SETREG IP = main
SETREG SP = 5FFE
ORG 1000

; Data blocks
;-------------
prompt: DB "Please enter a list of space-delimited "
        DB "positive decimal integers.", CR, LF, "$"
leader: DB "The maximum integer was: "
output: DB "        ", CR, LF, "$"
maxWord: DW 0000
inBuff: DB BLOCK 256 {'$'}

; Main routine
;-------------

; Start with a banner/prompt
main:   LEA DX, prompt
        INT write_str

        ; Read the string
        LEA DX, inBuff
        MOV CX, %255
        INT read_str

        ; Cap it with a dollar
        LEA DI, inBuff
        ADD DI, CX
        MOV BYTE [DI], '$'

        ; Start parsing @ char zero (use DI as the index during parsing/scanning)
	LEA DI, inBuff

        ; Scan for first digit (jump to output if we hit a dollar)
scan:   CMP BYTE [DI], '$'
        JE answer
        CMP BYTE [DI], '0'
        JL scan2
        CMP BYTE [DI], '9'
        JL parse
scan2:  INC DI
        JMP scan 

        ; Now actually parse!
parse:  MOV DX, DI
        INT atoi
        
        ; Add the character-scan-count to the scan-index
        ADD DI, CX
        
        ; Check to see if this int is the MAX
        CMP AX, maxWord
        JL scan
        
        ; New max!
        MOV maxWord, AX

        ; Loop back and continue the process
        JMP scan

        ; Now actually print the results (first itoa the max integer)
answer: LEA DX, output
        MOV AX, maxWord
        INT itoa

        ; PRINT!
        LEA DX, leader
        INT write_str

; Final termination
end:    HLT