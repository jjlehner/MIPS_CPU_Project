#divu
#1
#2
#testing remainder

addiu $3, $0, 0x0017
addiu $4, $0, 0x0004
divu $3, $4
mfhi $2
jr $0
nop
