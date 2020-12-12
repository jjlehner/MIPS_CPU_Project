#lwr
#1
#1
#none

lui $2, 0x0000
lui $16, 0x2000
lui $17, 0x1000
sw $17, 0($16)
lwr $2, 4($16)
jr $0
nop
