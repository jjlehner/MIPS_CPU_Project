#blez
#15
#1
#0xFFFFFFFF represented as -1, signed

	lui $t0, 0xFFFF
	addiu $t0, $t0, 0xFFFF 

	blez $t0, Target

	addiu $v0, $t0, 0x1000

	jr $zero

Target: addiu $v0, $t0, 0x0010

jr $zero

