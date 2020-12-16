#mult
#-6
#2
#none

addiu $t0, $zero, 0x0003
lui $t1, 0xFFFF
addiu $t1, $zero, 0xFFFE
mult $t0, $t1
mflo $v0
jr $zero
nop
