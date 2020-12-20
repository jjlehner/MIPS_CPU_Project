#div
#13
#3
#none
#40000/4999

lui $t0, 0x4
addiu $t1, $zero, 0x4999
div $t0, $t1
mflo $v0
jr $zero
nop
