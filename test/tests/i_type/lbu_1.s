#lbu 
#254
#1
#none

lui $t0, 0xBFE0
lui $t1, 0x1000
ori $t1, $t1, 0x00FE
sw $t1, 0($t0)
lbu $v0, 0($t0)
jr $zero
nop

