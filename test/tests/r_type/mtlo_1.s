#mtlo
#16
#1
#make sure mfhi is working

addiu $t1, $zero, 0x0010
mtlo $t1
mflo $v0
jr $zero
nop
