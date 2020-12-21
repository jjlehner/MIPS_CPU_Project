#addu
#0
#1
#addition between signed values, check lui, addiu and jr works

lui $t0, 0xFFFF
addiu $t0, $t0, 0xFFFF

addiu $t1, $zero, 0x0001

addu $v0, $t0, $t1

jr $zero

nop
