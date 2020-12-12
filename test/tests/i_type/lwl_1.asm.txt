#lwl
#16
#1
#none

lui $2, 0x0000
lui $16, 0x1000
addiu $17, $0, 0x0010
sw $17, 0($16)
lwl $2, 0($16)
jr $0
nop
