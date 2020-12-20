#slti
#2
#4

ori   $v0, $0, 1
l1:
addu  $v0, $v0, $v0
slti  $a0, $v0, 0x7FFF
bne   $a0, $0,  l1
jr $0

