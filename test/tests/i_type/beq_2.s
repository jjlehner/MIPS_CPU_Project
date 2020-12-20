#beq
#69632
#2
#not equal should not branch
.set noreorder 
.set nomacro
	lui $t0, 0x0001
	lui $t1, 0x0010

	beq $t0, $t1, Target
	nop

	addiu $v0, $t0, 0x1000

	jr $zero
	nop
Target: addiu $v0, $t0, 0x0010

jr $zero

