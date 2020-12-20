#sra
#2147483647
#1
#none

lui $t0, 0xFFFF
addiu $t0, $t0, 0xFFFE

sra $v0, $t0, 1

jr $zero
nop
