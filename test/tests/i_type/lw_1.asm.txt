#lw 
#0
#1
#additional comment : none

lui $4, 0x3600

lui $3, 0x1000

sw $3, 0x1000($4)

addiu $4, $4, 0x1000
lw $5, 0($4)

subu $2, $5, $3

jr $0
nop

