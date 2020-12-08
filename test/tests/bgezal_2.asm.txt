#bgezal
#4112
#2
#testing bgez and link together


	lui $3, 0x0000

	bgezal $3, Target

	addiu $2, $3, 0x1000

	jr $0

Target: addiu $3, $3, 0x0010

jr $31

