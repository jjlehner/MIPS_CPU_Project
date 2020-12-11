#j
#16
#1
#testing the if j works correctly, must ensure jr works 

	lui $3, 0x0000

	j Target

	addiu $2, $3, 0x1000
	
	jr $0

Target: addiu $2, $3, 0x0010

jr $0

