#sltu
#1
#1
#set $2 to 1 when $3 is LESS THAN $4 (unsigned)

lui $t0, 0x1000
lui $t1, 0x2000

sltu $v0, $t0, $t1

jr $zero
nop
