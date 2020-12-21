#bgez
#16
#1
#as 1 , branching should succede and $v0 = 16 not $v0 = 16
.set noreorder 
.set nomacro
	lui $t0, 0x0001

	bgez $t0, Target

	nop

	addiu $v0, $t0, 0x0001

	jr $zero
	nop
Target: addiu $v0, $0, 0x0010

jr $zero

