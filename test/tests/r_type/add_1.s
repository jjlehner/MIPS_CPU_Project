#add
#0
#1
#addition between signed values, check lui, addiu and jr works

lui $3, 0xFFFF
addiu $3, $3, 0xFFFF

addiu $4, $0, 0x0001

add $2, $3, $4

jr $0

nop
