#sb 
#0
#1
#additional comment : both sb and lb must be working

addiu $t1, $zero, 0x0A00

lui $t0, 0xBABE
addiu $t0, $t0, 0xA000
lui $a0, 0xFFFF
addiu $a0, $a0, 0xFFA0
sb $t0, 1($t1)

addiu $t1, $t1, 1

lb $t2, 0($t1)

subu $v0, $t2, $a0

jr $zero
nop

