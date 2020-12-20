#j
#61442
#3

ori   $t0, $0, 0x2
j     0xC 
nop
addiu $t0, $0, 0xff
ori   $v0, $t0, 0xf000
jr $0

