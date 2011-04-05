;Jonathan Zimmerman
;A TEST FOR MOVING WORDS FROM REGISTER TO REGISTER   
;TESTS ALL REGISTERS
;AFTER EXECUTION, AX SHOULD CONTAIN VALUE 3412

org 1000
setreg ip = begin
setreg sp = 5fff
begin:    MOV AX,1234
	MOV [0000],AX
	MOV BX,[0000]
	MOV [0002],BX
	MOV CX,[0002]
	MOV [0004],CX
	MOV DX,[0004]

;          MOV SI,DX
;          MOV DI,SI
;          MOV BP,DI
;          MOV SS,BP
;          MOV DS,BP
;          MOV ES,BP
;         MOV CS,BP  <-- DO NOT DO!!!!
;          MOV CH,AL
;          MOV CL,AH
;          MOV BL,CL
;          MOV BH,CH
;          MOV DL,BL
;          MOV DH,BH
;          MOV AH,DH
;          MOV AL,DL
	HLT
