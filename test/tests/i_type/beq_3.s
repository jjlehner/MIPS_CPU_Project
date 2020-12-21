#beq
#1
#3
#testing extreme inequality FFFF /= FFFE ?  so $v0 = 0001 not FFFF
.set noreorder 
.set nomacro

	lui $t0, 0xFFFF
	lui $t1, 0xFFFE

	beq $t0, $t1, Target

    nop

	addiu $v0, $0, 0x0001

	jr $zero
	nop
Target: addiu $v0, $t0, 0xFFFF

jr $zero
