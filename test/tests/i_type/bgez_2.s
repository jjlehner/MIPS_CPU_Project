#bgez
#16
#2
#none

	lui $t0, 0x0000

	bgez $t0, Target

	addiu $v0, $t0, 0x1000

	jr $zero

Target: addiu $v0, $t0, 0x0010

jr $zero

