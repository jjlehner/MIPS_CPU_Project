#sltu
#1
#2
#set $2 to 1 when $3 is LESS THAN $4 (unsigned)

lui $3, 0x1000
lui $4, 0xFFFF

sltu $2, $3, $4

jr $0
nop
