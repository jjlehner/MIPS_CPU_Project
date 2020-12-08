#jal
#69648
#1
#testing the if jal works correctly, must ensure jr works 

	lui $3, 0x0001

	jal Target

	addiu $2, $3, 0x1000
	
	jr $0

Target: addiu $3, $3, 0x0010

jr $31

