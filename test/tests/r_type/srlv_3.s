#srlv
#4096
#3
#none

lui $3, 0x0010
addiu $4, $0, 0x0008

srlv $2, $3, $4

jr $0
nop