#div
#-8
#1
#none

addiu $3, $0, 0x0010
lui $4, 0xFFFF
addiu $4, $0, 0xFFFE
div $3, $4
mflo $2
jr $0
nop
