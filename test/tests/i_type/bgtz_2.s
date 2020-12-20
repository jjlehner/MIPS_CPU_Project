#bgtz
#256
#2
#none

	lui $t0, 0x0000

	bgtz $t0, Target

	addiu $v0, $t0, 0x0100

	jr $zero

Target: addiu $v0, $t0, 0x0010

jr $zero

