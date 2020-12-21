#bgez
#16
#2
#0x0000 is 0 , branching should succede and $v0 = 16 not $v0 = 1
.set noreorder 
.set nomacro
	lui $t0, 0x0000

	bgez $t0, Target

	nop

	addiu $v0, $t0, 0x0001

	jr $zero
	nop
Target: addiu $v0, $t0, 0x0010

jr $zero

