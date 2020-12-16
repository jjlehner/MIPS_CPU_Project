#nor
#14
#1
#lui and addiu should be working

lui $3, 0xFFFF
addiu $4, $0, 0xFFF1

nor $2, $3, $4

jr $0
nop
