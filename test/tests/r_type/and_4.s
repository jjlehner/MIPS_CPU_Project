#and
#4294901760
#4
#extreme bitwise and FFFF & FFFF = FFFF

lui $t0, 0xFFFF
lui $t1, 0xFFFF

and $v0, $t0, $t1

jr $zero
