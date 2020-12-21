#sw
#32
#1
#Check the offsetting on addresses

addiu $t0, $zero, 5 
addiu $t1, $zero, 32
sw $t1, 3($t0)

addiu $t0, $t0, 3

lw $v0, 0($t0)

jr $zero
nop
