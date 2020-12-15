#lwl
#256
#2
#none

lui $2, 0x0000
lui $16, 0x2000
lui $17, 0xF000
addiu $17, $0, 0x0010
sw $17, 0($16)
lwl $2, 4($16)
jr $0
nop
