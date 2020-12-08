#sb
#5
#2
#additional comment : both sb and lb must be working

addiu $3, $0, 5 
addiu $4, $0, 32
sb $3, 1($4)

addiu $4, $4, 1

lb $2, 0($4)

jr $0
nop
