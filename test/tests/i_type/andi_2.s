#andi
#256
#2
#bitwise andi

lui $t0, 0x0001
ori $t0, $t0, 0x0100

andi $v0, $t0, 0x100

jr $zero

