#multu
#33554432
#1
#none

lui $a1, 0x1000
lui $a2, 0x2000
multu $a1, $a2
mfhi $v0
jr $0
