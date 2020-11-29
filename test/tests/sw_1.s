#sw
#5
#sw_1
#testing dependencies: addiu, lw, jr

addiu $3, $0, 5 
addiu $4, $0, 32
sw $3, 1($4)

addiu $4, $4, 1

lw $2, 0($4)

jr $0
nop
