#sltiu
#65536
#4

ori   $v0, $0, 1
l1:
addu  $v0, $v0, $v0
sltiu $a0, $v0, 0xFFFF
bne   $a0, $0,  l1
jr $0

