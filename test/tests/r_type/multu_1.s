#multu
#16
#1
#none

addiu $t0, $zero, 0x0002
addiu $t1, $zero, 0x0008
mult $t0, $t1
mflo $v0
jr $zero
nop
