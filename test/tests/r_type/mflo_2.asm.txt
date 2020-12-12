#mflo
#3
#2
#make sure div is working

addiu $3, $0, 0x000E
addiu $4, $0, 0x0004
div $3, $4
mflo $2
jr $0
nop
