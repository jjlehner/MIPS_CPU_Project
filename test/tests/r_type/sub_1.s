#sub
#65536
#1
#subtraction between two unsigned values, check lui works

lui $t0, 0x0010
lui $t1, 0x000F

sub $v0, $t0, $t1

jr $zero

nop
