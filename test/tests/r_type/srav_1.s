#srav
#4294967295
#1
#none

lui $t0, 0xFFFF
addiu $t0, $t0, 0xFFFE

addiu $t1, $zero, 0x0001

srav $v0, $t0, $t1

jr $zero
nop
