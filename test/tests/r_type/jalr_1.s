#jalr
#1
#1

lui $15, 0x1000
ori $15, $15, 0x0018
jalr $15
nop
ori $2, $2, 0x0001
jr $0
nop


