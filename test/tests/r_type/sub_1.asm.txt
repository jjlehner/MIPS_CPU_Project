#sub
#65536
#1
#subtraction between two unsigned values, check lui works

lui $3, 0x0010
lui $4, 0x000F

sub $2, $3, $4

jr $0

nop
