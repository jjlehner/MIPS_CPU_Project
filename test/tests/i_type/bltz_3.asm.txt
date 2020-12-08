#bltz
#69632
#3
#does not branch

	lui $3, 0x0001

	bltz $3, Target

	addiu $2, $3, 0x1000

	jr $0	

Target: addiu $2, $3, 0x0010

jr $0

