#slti
#1
#1
#set $2 to 1 when $3 is LESS THAN immediate, signed

lui $3, 0xFFFF

slti $2, $3, 0x0000

jr $0
