#lb
#80
#2
#none

	lui $t0, 0x0001
	addiu $t0, $0, 0x5040
	addiu $t1, $0, 0x0020
	sw $t0, 0($t1)
	addiu $t1, $t1, 0x0001
	lb $v0, 0($t1)
	jr $zero
	nop
