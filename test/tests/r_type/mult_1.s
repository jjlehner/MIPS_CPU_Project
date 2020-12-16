#mult
#-2
#1
#none

addiu $t0, $zero, 0x0002
lui $t1, 0xFFFF
addiu $t1, $zero, 0xFFFF
mult $t0, $t1
mflo $v0
jr $zero
nop
