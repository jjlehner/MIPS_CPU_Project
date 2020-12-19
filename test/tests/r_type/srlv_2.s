#srlv
#4096
#2
#none

lui $t0, 0x0001
addiu $t1, $zero, 0x0004

srlv $v0, $t0, $t1

jr $zero
nop
