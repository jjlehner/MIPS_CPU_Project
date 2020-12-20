#bltzal
#69632
#1
#testing the bltz and link 
.set noreorder 
.set nomacro
	lui $t0, 0x0001

	bltzal $t0, Target

	addiu $v0, $t0, 0x1000
	
	jr $zero
	nop
Target: addiu $t0, $t0, 0x0010

jr $ra

