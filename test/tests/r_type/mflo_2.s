#mflo
#3
#2
#make sure div is working

addiu $t0, $zero, 0x000E
addiu $t1, $zero, 0x0004
div $t0, $t1
mflo $v0
jr $zero
nop
