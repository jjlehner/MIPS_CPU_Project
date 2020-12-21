#mfhi
#4
#1
#make sure mthi is working

addiu $t1, $0, 0x0004
mthi $t1
mfhi $v0
jr $zero
nop
