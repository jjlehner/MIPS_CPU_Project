#beq
#65535
#4
#testing extreme equality FFFF == FFFF ? if so $v0 = FFFF

	lui $t0, 0xFFFF
	lui $t1, 0xFFFF

	beq $t0, $t1, Target

	nop

	jr $zero

Target: addiu $v0, $t0, 0xFFFF

jr $zero