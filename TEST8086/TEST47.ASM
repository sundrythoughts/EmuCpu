; This program simulates a piano keyboard
;
; Z=C note;  S=C# note; X=D note; etc ...
;
; The actual format is
;   S D   G H J
;  Z X C V B N M ,
;
; corresponding to
;   C#D#  F#G#A#
;  C D E F G A B C
;
setreg ip=begin
setreg sp=5fff
org 100
stop:
  hlt
begin:
  mov bx,1
  mov cx,%250
  lea dx,[instruct]
  int 10
  xor dx,dx
loop:
  xor ax,ax
  in al,1
  xchg ax,dx
  cmp dx,%97
  jl doit
  sub dx,%32
doit:
  cmp dx,'Z'
  je cnote
  cmp dx,'S'
  je csnote
  cmp dx,'X'
  je dnote
  cmp dx,'D'
  je dsnote
  cmp dx,'C'
  je enote
  cmp dx,'V'
  je fnote
  cmp dx,'G'
  je fsnote
  cmp dx,'B'
  je gnote
  cmp dx,'H'
  je gsnote
  cmp dx,'N'
  je anote
  cmp dx,'J'
  je asnote
  cmp dx,'M'
  je bnote
  cmp dx,','
  je c2note
  cmp dx,'Q'
  je stop
  jmp loop
play:
  out 3,ax
  jmp loop
cnote:
  mov ax,%262
  jmp play
csnote:
  mov ax,%277
  jmp play
dnote:
  mov ax,%294
  jmp play
dsnote:
  mov ax,%311
  jmp play
enote:
  mov ax,%330
  jmp play
fnote:
  mov ax,%349
  jmp play
fsnote:
  mov ax,%370
  jmp play
gnote:
  mov ax,%392
  jmp play
gsnote:
  mov ax,%415
  jmp play
anote:
  mov ax,%440
  jmp play
asnote:
  mov ax,%466
  jmp play
bnote:
  mov ax,%494
  jmp play
c2note:
  mov ax,%524
  jmp play
instruct:
  db "Type Keys Z=C S=C# X=D ... Q=Quit"
  db %13
  db %10
  db "$"

