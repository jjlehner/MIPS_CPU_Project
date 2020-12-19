#slt
#0
#2
#set $2 to 0 when $3 is NOT LESS THAN $4

lui $t0, 0x1000
lui $t1, 0x1000

slt $v0, $t0, $t1

jr $zero
nop
