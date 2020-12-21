#lhu
#65534
#2
#unsigned load halfword

ori $sp, $0, 4
lui $t1, 0xCCCC
ori $t1, $t1, 0xFFFE
sw $t1, 0($sp)
lhu $v0, 0($sp)
jr $zero
nop
