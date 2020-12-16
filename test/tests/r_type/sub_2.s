#sub
#1
#2
#additional comment: subtraction between two signed values

lui $3, 0xFFFF
addiu $3, $3, 0xFFFF

lui $4, 0x000F
addiu $4, $4, 0xFFFE

sub $2, $3, $4

jr $0

nop
