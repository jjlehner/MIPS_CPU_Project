#bltzal
#256
#2
#testing bltz and link together
.set noreorder 
.set nomacro

	lui $t0, 0x0000

	bltzal $t0, Target

	addiu $v0, $t0, 0x0100

	jr $zero
	nop
Target: addiu $t0, $t0, 0x0010

jr $ra

