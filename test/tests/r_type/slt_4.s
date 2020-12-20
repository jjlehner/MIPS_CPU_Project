#slt
#134217728
#4

lui   $t0, 0x7FF
ori   $t0, $t0, 0xffff
ori   $v0, $0, 1
l1:
addu  $v0, $v0, $v0
slt   $a0, $v0, $t0
bne   $a0, $0,  l1
jr $0

