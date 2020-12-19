#lwl
#256
#2
#none

lui $v0, 0x0000
lui $t0, 0x2000
lui $t1, 0xF000
addiu $t1, $zero, 0x0010
sw $t1, 0($t0)
lwl $2, 4($t0)
jr $zero
nop
