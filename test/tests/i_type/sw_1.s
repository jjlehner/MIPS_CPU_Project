#sw
#5
#1
#additional comment : none

addiu $t0, $zero, 5 
addiu $t1, $zero, 32
sw $t0, 1($t1)

addiu $t1, $t1, 1

lw $v0, 0($t1)

jr $zero
nop
