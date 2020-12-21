#sb
#5
#2
#additional comment : both sb and lb must be working

addiu $t0, $zero, 0x0500 
addiu $t1, $zero, 32
sb $t0, 0x0001($t1)

addiu $t1, $t1, 0x0001

lb $v0, 0x0000($t1)

jr $zero
nop
