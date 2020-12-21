#and
#65536
#1
#bitwise and

lui $t0, 0x0001
lui $t1, 0x0FFF

and $v0, $t0, $t1

jr $zero
