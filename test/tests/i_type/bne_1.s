#bne
#65552
#1
#failed to branch when registers were not equal 
.set noreorder 
.set nomacro
	lui $t0, 0x0001
	lui $t1, 0x00FE

	bne $t0, $t1, Target

	addiu $v0, $t0, 0x1000

	jr $zero
	nop
Target: addiu $v0, $t0, 0x0010

jr $zero

