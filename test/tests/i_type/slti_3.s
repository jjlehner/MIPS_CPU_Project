#slti
#1
#3
#set $2 to 1 when $3 is LESS THAN immediate, signed

lui $3, 0xFFFF

slti $2, $3, 0xFFFE

jr $0
