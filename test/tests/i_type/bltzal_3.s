#bltzal
#31
#3
#testing bgezal part only, check branching occurs when $3<0
.set noreorder 
.set nomacro
	lui $t0, 0xFFFF
	addiu $t0, $t0, 0xFFFF 

	bltzal $t0, Target
	addiu $v0, $t0, 0x0020

	jr $zero
	nop
Target: addiu $t0, $t0, 0x0010

jr $ra

