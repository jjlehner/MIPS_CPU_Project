#lwr
#2
#1
#Load the most significant byte of 0x10001111 (0x10 = 2)

lui $v0, 0x0000
lui $t1, 0x1000
ori $t1, $t1, 0x1111
ori $sp, $0, 8
sw $t1, 0($sp)
lwr $v0, 3($sp)
jr $0
nop
