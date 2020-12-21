#divu
#2
#1
#none
.set noreorder 
.set nomacro
addiu $t0, $zero, 0x0010
addiu $t1, $zero, 0x0008
divu $t0, $t1
mflo $v0
jr $zero
nop
