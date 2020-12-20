#lwr
#17
#1
#Load the 3 most significant bytes of 0x10001111 (0x10001100 = 17)

lui $v0, 0x0000
lui $t1, 0x1000
ori $t1, $t1, 0x1111
ori $sp, $0, 8
sw $t1, 0($sp)
lwr $v0, 3($sp)
jr $0
nop
