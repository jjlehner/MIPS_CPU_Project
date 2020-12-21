#sub
#1
#2
#additional comment: subtraction between two signed values

lui $t0, 0xFFFF
addiu $t0, $t0, 0xFFFF

lui $t1, 0x000F
addiu $t1, $t1, 0xFFFE

sub $v0, $t0, $t1

jr $zero

nop
