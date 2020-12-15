#slt
#0
#3
#set $2 to 0 when $3 is NOT LESS THAN $4

lui $3, 0x1000
lui $4, 0x0001

slt $2, $3, $4

jr $0
nop
