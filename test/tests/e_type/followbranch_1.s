#follow_branch
#0xFFFE
#1
#addition comment: check reg1 = 0xFFFF, reg2 = 0xFFFE; checking instruction after branch is executed

beq $0, $0, 0x0003
lui $1, 0xFFFF
lui $2, 0xFFFE
jr $0
nop
