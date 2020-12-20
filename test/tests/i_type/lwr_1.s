#lwr
#17
#1
#none

lui $v0, 0x0000
lui $t1, 0x1000
ori $t1, 0x1111
ori $sp, $0, 8
sw $t1, 0($t0)
lwr $v0, 3($t0)
jr $0
nop
