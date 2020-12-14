#addu 
#25
#1
#ensure addiu works

addiu $t1, $zero, 16
addiu $t2, $zero, 9

addu $v0, $t1, $t2

jr $zero

nop
