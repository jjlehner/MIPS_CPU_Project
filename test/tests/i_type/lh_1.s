#lh
#4294967294
#1
#signed load halfword

lui $t0, 0xBFF0
addiu $t1, $zero, 0xFFFE
sw $t1, 0($t0)
lh $v0, 0($t0)
jr $zero
nop
