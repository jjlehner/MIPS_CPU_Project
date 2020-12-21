#div
#3
#2
#none
.set noreorder 
.set nomacro
addiu $t0, $zero, 0x0017
addiu $t1, $zero, 0x0004
div $t0, $t1
mfhi $v0
jr $zero
nop
