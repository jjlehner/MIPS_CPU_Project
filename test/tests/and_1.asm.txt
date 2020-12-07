#and
#65536
#1
#bitwise and

lui $3, 0x0001
lui $4, 0x0FFF

and $2, $3, $4

jr $0
