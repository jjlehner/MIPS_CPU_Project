#bltzal
#69632
#1
#testing the bltz and link 

	lui $3, 0x0001

	bltzal $3, Target

	addiu $2, $3, 0x1000
	
	jr $0

Target: addiu $3, $3, 0x0010

jr $31

