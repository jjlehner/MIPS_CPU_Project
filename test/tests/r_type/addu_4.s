#addu 
#4294901760
#4
#extreme addition two FFFE + 0001 = FFFF

lui $t1, 0xFFFE
lui $t2, 0x0001

addu $v0, $t1, $t2

jr $zero

nop
