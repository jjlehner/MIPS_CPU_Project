#sra
#-1
#1
#none

lui $3, 0xFFFF
addiu $3, $0, 0xFFFE

sra $2, $3, 1

jr $0
nop