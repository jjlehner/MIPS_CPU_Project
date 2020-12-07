#bgez
#255
#3
#0xFFFF as -1, signed

	lui $3, 0xFFFF
	addiu $3, $3, 0xFFFF 
	
	bgez $3, Target

	addiu $2, $3, 0x0100

	jr $0

Target: addiu $2, $3, 0x0010

jr $0

