#bgezal
#16
#2
#testing bgez and link together
.set noreorder 
.set nomacro

	lui $t0, 0x0000

	bgezal $t0, Target

	addiu $v0, $t0, 0x1000

	jr $zero
	nop
Target: addiu $v0, $t0, 0x0010

jr $ra

