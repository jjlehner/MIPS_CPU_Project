#lwl
#16
#1
#none

lui $v0, 0x0000
lui $t0, 0x1000
addiu $t1, $zero, 0x0010
sw $t1, 0($t0)
lwl $v0, 0($t0)
jr $zero
nop
