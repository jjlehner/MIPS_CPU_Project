#srlv
#4096
#3
#none

lui $t0, 0x0010
addiu $t1, $zero, 0x0008

srlv $v0, $t0, $t1

jr $zero
nop
