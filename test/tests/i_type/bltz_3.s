#bltz
#69632
#3
#does not branch
.set noreorder 
.set nomacro
	lui $t0, 0x0001

	bltz $t0, Target

	addiu $v0, $t0, 0x1000

	jr $zero	
	nop
Target: addiu $v0, $t0, 0x0010

jr $zero

