#sllv
#65536
#1
#none

addiu $t0, $zero, 0x0001
addiu $t1, $zero, 0x0010

sllv $v0, $t0, $t1

jr $zero
nop
