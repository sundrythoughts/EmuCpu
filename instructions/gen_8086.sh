#!/bin/bash

cat 8086_AddressingModes.dat | grep -e "^[^\#][^\n].*" | awk -F% '{print "{ \x27" $1 "\x27, \"" $2 "\" },"}' > AddressingModes8086.h
echo -e "{ 0, 0 };" >> AddressingModes8086.h

cat 8086_OperandTypes.dat | grep -e "^[^\#][^\n].*" | awk -F% '{print "{ \"" $1 "\", \"" $2 "\" },"}' > OperandTypes8086.h
echo -e "{ 0, 0 };" >> OperandTypes8086.h
