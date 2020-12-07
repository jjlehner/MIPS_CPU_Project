#bne
#69632
#2
#none

	lui $3, 0x0001
	lui $4, 0x0001

	bne $3, $4, Target

	addiu $2, $3, 0x1000

	jr $0

Target: addiu $2, $3, 0x0010

jr $0

