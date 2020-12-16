#bgez
#65552
#1
#t0 is greater than 0

	lui $t0, 0x0001

	bgez $t0, Target

	addiu $v0, $t0, 0x1000

	jr $zero

#Target
	addiu $v0, $t0, 0x0010

	jr $zero

