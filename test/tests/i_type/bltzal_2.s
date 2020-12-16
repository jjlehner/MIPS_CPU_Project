#bltzal
#256
#2
#testing bltz and link together


	lui $t0, 0x0000

	bltzal $t0, Target

	addiu $v0, $t0, 0x0100

	jr $zero

Target: addiu $t0, $t0, 0x0010

jr $ra

