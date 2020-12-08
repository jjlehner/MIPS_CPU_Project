#bgtz
#256
#2
#none

	lui $3, 0x0000

	bgtz $3, Target

	addiu $2, $3, 0x0100

	jr $0

Target: addiu $2, $3, 0x0010

jr $0

