#blez
#69632
#3
#none

	lui $3, 0x0001

	blez $3, Target

	addiu $2, $3, 0x1000

	jr $0

Target: addiu $2, $3, 0x0010

jr $0

