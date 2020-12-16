#mult
#-2
#1
#none

addiu $3, $0, 0x0002
lui $4, 0xFFFF
addiu $4, $0, 0xFFFF
mult $3, $4
mflo $2
jr $0
nop
