#bne
#69632
#2
#failed to not branch when the registers were equal 
.set noreorder 
.set nomacro
	lui $t0, 0x0001
	lui $t1, 0x0001

	bne $t0, $t1, Target

	addiu $v0, $t0, 0x1000

	jr $zero
	nop
Target: addiu $v0, $t0, 0x0010

jr $zero

