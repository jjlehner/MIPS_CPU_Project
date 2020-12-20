#sltu
#0
#3

ori   $t0, $0, 0x1
ori   $v0, $0, 1
l1:
addu  $v0, $v0, $v0
sltu  $a0, $v0, $t0
beq   $a0, $0,  l1
jr $0

