#bne
#65552
#1
#branch since not equal

	lui $3, 0x0001
	lui $4, 0x00FE

	bne $3, $4, Target

	addiu $2, $3, 0x1000

	jr $0

Target: addiu $2, $3, 0x0010

jr $0

