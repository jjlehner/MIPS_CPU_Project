#lbu 
#254
#1
#none

lui $16, 0x2000
lui $18, 0x1000
ori $18, $18, 0x00FE
sw $18, 0($16)
lbu $2, 0($16)
jr $0
nop

