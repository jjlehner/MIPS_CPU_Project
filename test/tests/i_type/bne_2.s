#bne
#69632
#2
#none

	lui $t0, 0x0001
	lui $t1, 0x0001

	bne $t0, $t1, Target

	addiu $v0, $t0, 0x1000

	jr $zero

Target: addiu $v0, $t0, 0x0010

jr $zero

