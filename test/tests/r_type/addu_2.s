#addu 
#65536
#2
#trying with lui dependency

lui $t1, 0x0001
lui $t2, 0x0000

addu $v0, $t1, $t2

jr $zero

nop
