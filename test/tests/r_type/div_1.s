#div
#4294967288
#1
#none
.set noreorder 
.set push
.set nomacro

	addiu $t0, $zero, 0x0010
	lui $t1, 0xFFFF
	addiu $t1, $t1, 0xFFFE
	div $t0, $t1
	mflo $v0
	jr $zero
	nop
.set pop