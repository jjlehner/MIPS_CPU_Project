#jalr
#3217031184
#1

lui $15, 0xBFC0
ori $15, $15, 0x000F
jalr $15
nop
addu $v0, $zero, $ra
jr $0
nop


