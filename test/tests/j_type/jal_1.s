#jal
#69648
#1
#testing the if jal works correctly, must ensure jr works 

	lui $t0, 0x0001

	jal 2

	addiu $v0, $t0, 0x1000
	
	jr $zero

#Target 
	addiu $t0, $t0, 0x0010

	jr $ra

