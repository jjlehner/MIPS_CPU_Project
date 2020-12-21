#addu 
#4294836224
#3
#trying an extreme unsigned number adding FFFF AND FFFF = 1FFFE

lui $t1, 0xFFFF
lui $t2, 0xFFFF

addu $v0, $t1, $t2

jr $zero

nop

