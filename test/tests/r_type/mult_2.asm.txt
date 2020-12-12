#mult
#-6
#2
#none

addiu $3, $0, 0x0003
lui $4, 0xFFFF
addiu $4, $0, 0xFFFE
mult $3, $4
mflo $2
jr $0
nop
