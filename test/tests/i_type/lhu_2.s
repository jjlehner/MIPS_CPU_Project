#lhu
#52428
#1
#signed load halfword

ori $sp, $0, 4
lui $t1, 0xcccc
ori $t1, $t1, 0xFFFE
sw $t1, 0($sp)
lhu $v0, 2($sp)
jr $zero
nop
