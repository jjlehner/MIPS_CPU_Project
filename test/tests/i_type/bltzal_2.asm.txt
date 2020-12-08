#bltzal
#256
#2
#testing bltz and link together


	lui $3, 0x0000

	bltzal $3, Target

	addiu $2, $3, 0x0100

	jr $0

Target: addiu $3, $3, 0x0010

jr $31

