#or
#4095
#1
#bitwise or

addiu $t0, $zero, 0x0001
addiu $t1, $zero, 0x0FFF

or $v0, $t0, $t1

jr $zero
nop
