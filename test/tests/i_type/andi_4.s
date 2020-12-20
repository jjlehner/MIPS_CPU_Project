#andi
#65535
#4
#extreme bitwise andi FFFF & FFFF = FFFF

lui $t0, 0xFFFF

andi $v0, $t0, 0xFFFF

jr $zero
