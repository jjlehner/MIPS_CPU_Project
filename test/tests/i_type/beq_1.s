#beq
#65552
#1
#none
.set noreorder 
.set nomacro
	lui $t0, 0x0001
	lui $t1, 0x0001

	beq $t0, $t1, Target
	nop

	addiu $v0, $t0, 0x1000

	jr $zero
	nop
Target: addiu $v0, $t0, 0x0010

jr $zero

