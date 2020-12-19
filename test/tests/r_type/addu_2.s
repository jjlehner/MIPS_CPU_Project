#addu 
#65536
#2
#trying with lui dependency

lui $v0, 0x0001
lui $t2, 0x0000

addu $v0, $v0, $t2

jr $zero

nop
