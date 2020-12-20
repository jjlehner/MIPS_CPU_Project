#srav
#33553544
#2

lui   $t0, 0x7FFF
ori   $t0, $t0, 0x2233
ori   $t1, $0, 0x6
srav  $v0, $t0, $t1
jr $0

