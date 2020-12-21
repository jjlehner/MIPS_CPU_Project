#bgez
#255
#3
#0xFFFF as -1, branching should fail and $v0 = 255 not $v0 = 16
.set noreorder 
.set nomacro
	lui $t0, 0xFFFF
	addiu $t0, $t0, 0xFFFF 
	
	bgez $t0, Target

	nop

	addiu $v0, $t0, 0x0100

	jr $zero
	nop
Target: addiu $v0, $t0, 0x0010

jr $zero

