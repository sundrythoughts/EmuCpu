         ORG      1000
         SETREG   IP=BEGIN
         SETREG   SP=5FFF
         SETREG   AX=0007
         SETREG   DX=0001
BEGIN:   CMP      AX,DX
         JB       STOP
         JBE      STOP
         JE       STOP
         JL       STOP
         JLE      STOP
         JO       STOP
         JS       STOP
         JA       DOWN1
TOP1:    JG       DOWN2
TOP2:    JNE      DOWN3
TOP3:    JNS      STOP
DOWN1:   JAE      TOP1
DOWN2:   JGE      TOP2
DOWN3:   JNO      TOP3
STOP:    HLT