#lh
#-2
#1
#signed load halfword

lui $16, 0x2000
addiu $18, 0xFFFE
sw $18, 0($16)
lh $2, 0($16)
jr $0
nop
