#mthi
#16
#1
#make sure mfhi is working

addiu $t1, $zero, 0x0010
mthi $t1
mfhi $v0
jr $zero
nop
