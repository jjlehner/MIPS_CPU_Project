#slti
#1
#1
#set $2 to 1 when $3 is LESS THAN immediate, signed

lui $t0, 0xFFFF

slti $v0, $t0, 0x0000

jr $zero
