#mflo
#4
#1
#make sure mthi is working

addiu $t1, $zero, 0x0004
mtlo $t1
mflo $v0
jr $zero
nop
