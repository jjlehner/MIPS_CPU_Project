#bgezal
#13
#3
#testing bgezal part only, check no branching when $3<0

	lui $3, 0xFFFF
	addiu $3, $3, 0xFFFF 

	bgezal $3, Target

	addiu $2, $3, 0x000E

	jr $0	

Target: addiu $3, $3, 0x0010

jr $31

