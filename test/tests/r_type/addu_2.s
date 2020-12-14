#addu 
#65536
#2
#trying with lui dependency

lui $3, 0x0001
lui $4, 0x0000

addu $2, $3, $4

jr $0

nop
