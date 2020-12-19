#lwr
#1
#1
#none

lui $v0, 0x0000
lui $t0, 0x2000
lui $t1, 0x1000
sw $t1, 0($t0)
lwr $v0, 4($t0)
jr $0
nop
