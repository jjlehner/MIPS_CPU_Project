#lw 
#65536
#1
#additional comment : none

ori $t1, $0, 4

lui $t0, 0x0001

sw $t0, 0x001($t1)

addiu $t1, $t1, 0x001
lw $v0, 0($t1)
jr $0
nop

