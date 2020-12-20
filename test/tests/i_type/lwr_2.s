#lwr
#5574947
#2

ori $sp, $0, 4
lui $t0, 0x5555
ori $t0, $0, 0x1123
sw  $t0, 0($sp)
lwr $v0, 1($sp)
jr $0

