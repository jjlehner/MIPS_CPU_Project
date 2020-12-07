#bltz
#15
#1
#0xFFFFFFFF represented as -1

	lui $3, 0xFFFF
	addiu $3, $3, 0xFFFF 

	bltz $3, Target

	addiu $2, $3, 0x0010
	
	jr $0

Target: addiu $2, $3, 0x0010

jr $0

