#lwl
#268435456
#1
#none

lui $v0, 0x1000
lui $t0, 0x0000
ori $sp, $0, 4
addiu $t1, $t0, 0x0010
sw $t1, 0($sp)
lwl $v0, 2($sp)
jr $zero
nop
