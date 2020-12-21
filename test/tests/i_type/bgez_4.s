#bgez
#0
#4
#0xFFFE as -2, branching should fail and $v0 = 0 not $v0 = 14
.set noreorder 
.set nomacro
	lui $t0, 0xFFFF
	addiu $t0, $t0, 0xFFFE 
	
	bgez $t0, Target

	nop

	addiu $v0, $t0, 0x0002

	jr $zero
	nop
Target: addiu $v0, $t0, 0x0010

jr $zero

