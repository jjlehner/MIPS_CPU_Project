#nor
#14
#1
#lui and addiu should be working

lui $t0, 0xFFFF
addiu $t1, $zero, 0xFFF1

nor $v0, $t0, $t1

jr $zero
nop
