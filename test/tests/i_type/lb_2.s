#lb
#5
#2
#none

lui $3, 0x0001
addiu $3, $0, 0x0005
addiu $4, $0, 32
sw $3, 1($4)
addiu $4, $4, 1
lb $2, 0($4)
jr $0
nop
