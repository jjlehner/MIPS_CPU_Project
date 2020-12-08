#bgez
#65552
#1
#$3 is greater than 0

	lui $3, 0x0001

	bgez $3, Target

	addiu $2, $3, 0x1000

	jr $0

Target: addiu $2, $3, 0x0010

jr $0

