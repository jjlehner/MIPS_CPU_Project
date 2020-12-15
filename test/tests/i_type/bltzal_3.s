#bltzal
#47
#3
#testing bgezal part only, check branching occurs when $3<0

	lui $3, 0xFFFF
	addiu $3, $3, 0xFFFF 

	bltzal $3, Target

	addiu $2, $3, 0x0020

	jr $0

Target: addiu $3, $3, 0x0010

jr $31

