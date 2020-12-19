#sb 
#0
#1
#additional comment : both sb and lb must be working

lui $t1, 0x1000

lui $t0, 0x0000

sb $t0, 1($t1)

addiu $t1, $t1, 1

lb $t2, 0($t1)

subu $v0, $t2, $t0

jr $zero
nop

