#lwl
#268435456
#2
#none

lui $v0, 0x0000
ori $t0, $0, 4
lui $t1, 0xF000
addiu $t1, $t1, 0x0010
sw $t1, 0($t0)
lwl $v0, 1($t0)
jr $zero
nop
