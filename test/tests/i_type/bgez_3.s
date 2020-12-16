#bgez
#255
#3
#0xFFFF as -1, signed

	lui $t0, 0xFFFF
	addiu $t0, $t0, 0xFFFF 
	
	bgez $t0, Target

	addiu $v0, $t0, 0x0100

	jr $zero

Target: addiu $v0, $t0, 0x0010

jr $zero

