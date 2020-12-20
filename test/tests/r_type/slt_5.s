#slt
#1
#5

lui $t0, 0x7ff
ori $t0, $t0, 0xffff
lui $t1, 1
slt $v0, $t1, $t0
jr $0

