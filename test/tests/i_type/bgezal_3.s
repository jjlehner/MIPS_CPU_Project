#bgezal
#13
#3
#testing bgezal part only, check no branching when $3<0
.set noreorder 
.set nomacro
	lui $t0, 0xFFFF
	addiu $t0, $t0, 0xFFFF 

	bgezal $t0, Target

	addiu $v0, $t0, 0x000E

	jr $zero
	nop	

Target: addiu $v0, $t0, 0x0010

jr $ra

