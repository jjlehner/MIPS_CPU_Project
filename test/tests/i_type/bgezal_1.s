#bgezal
#69648
#1
#testing the bgez and link 

	lui $3, 0x0001

	bgezal $3, Target

	addiu $2, $3, 0x1000
	
	jr $0

Target: addiu $3, $3, 0x0010

jr $31

