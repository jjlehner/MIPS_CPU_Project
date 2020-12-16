#div
#-8
#1
#none

addiu $t0, $zero, 0x0010
lui $t1, 0xFFFF
addiu $t1, $zero, 0xFFFE
div $t0, $t1
mflo $v0
jr $zero
nop
