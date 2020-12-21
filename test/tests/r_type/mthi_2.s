#mthi
#0
#1
#make sure mfhi is working

addiu $t1, $zero, 0x0010
mthi $t1
mflo $v0
jr $zero
nop