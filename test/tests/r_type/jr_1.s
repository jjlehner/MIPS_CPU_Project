#jr
#20
#1
#additional comment : none

addiu $t0, $zero, 0x0010
jal 0x0004 
addiu $v0, $v0, 0x0004
jr $zero
addiu $v0, $t0, 0x0000
jr $ra



