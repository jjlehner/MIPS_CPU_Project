#subu 
#7
#1
#ensure addiu works

addiu $t1, $zero, 0x0010
addiu $t0, $zero, 0x0009

subu $v0, $t1, $t0

jr $zero

nop
