#mult
#4294967290
#2
#none

addiu $t0, $zero, 0x0003
lui $t1, 0xFFFF
addiu $t1, $t1, 0xFFFE
mult $t0, $t1
mflo $v0
jr $zero
nop
