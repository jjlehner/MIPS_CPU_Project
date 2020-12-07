#blez
#15
#1
#0xFFFFFFFF represented as -1, signed

	lui $3, 0xFFFF
	addiu $3, $3, 0xFFFF 

	blez $3, Target

	addiu $2, $3, 0x1000

	jr $0

Target: addiu $2, $3, 0x0010

jr $0

