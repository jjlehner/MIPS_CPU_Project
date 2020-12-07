#bgez
#16
#2
#none

	lui $3, 0x0000

	bgez $3, Target

	addiu $2, $3, 0x1000

	jr $0

Target: addiu $2, $3, 0x0010

jr $0

