#bgtz
#65552
#1
#none

	lui $t0, 0x0001

	bgtz $t0, Target

	addiu $v0, $t0, 0x1000

	jr $zero

Target: addiu $v0, $t0, 0x0010

jr $zero

