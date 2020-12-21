#bltz
#15
#1
#0xFFFFFFFF represented as -1
.set noreorder 
.set nomacro
	lui $t0, 0xFFFF
	addiu $t0, $t0, 0xFFFF 

	bltz $t0, Target

	addiu $v0, $t0, 0x0010
	
	jr $zero
	nop
Target: addiu $v0, $t0, 0x0010

jr $zero

