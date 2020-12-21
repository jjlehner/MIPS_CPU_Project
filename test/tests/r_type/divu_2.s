#divu
#3
#2
#testing remainder

.set noreorder 
.set nomacro
addiu $t0, $zero, 0x0017
addiu $t1, $zero, 0x0004
divu $t0, $t1
mfhi $v0
jr $zero
nop
