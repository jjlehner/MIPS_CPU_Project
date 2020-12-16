#sb
#5
#3
#additional comment : both sb and lb must be working, ensure the lower byte is stored and loaded

lui $t0, 0x0001
addiu $t0, $zero, 0x0005
 
addiu $t1, $zero, 32

sb $t0, 0x0001($t1)

addiu $t1, $t1, 0x0001

lb $v0, 0($t1)

jr $zero
nop
