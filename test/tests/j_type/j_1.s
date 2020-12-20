#j
#16
#1
#testing the if j works correctly, must ensure jr works 

	lui $t0, 0x0000

	j Target
  nop
	addiu $v0, $t0, 0x1000
	jr $zero
  nop

Target: addiu $v0, $t0, 0x0010
jr $zero

