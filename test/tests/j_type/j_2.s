#j
#
#2

ori   $t0, $0, 0x2
j     2
nop
addiu $t0, $0, 0xff
ori   $v0, $t0, 0
jr $0

