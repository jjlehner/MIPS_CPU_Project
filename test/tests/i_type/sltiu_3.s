#sltiu
#0
#3
#set $2 to 1 when $3 is LESS THAN immediate, unsigned

lui $3, 0xFFFF

sltiu $2, $3, 0x0000

jr $0
