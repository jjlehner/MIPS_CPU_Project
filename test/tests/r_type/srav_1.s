#srav
#-1
#1
#none

lui $3, 0xFFFF
addiu $3, $0, 0xFFFE

addiu $4, $0, 0x0001

srav $2, $3, $4

jr $0
nop