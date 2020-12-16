#lhu
#65534
#1
#signed load halfword

lui $t0, 0x2000
addiu $t1, 0xFFFE
sw $t1, 0($t0)
lh $v0, 0($t0)
jr $zero
nop
