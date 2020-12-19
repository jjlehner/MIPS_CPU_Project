#follow_branch
#0xFFFF
#1
#addition comment: check reg2 = 0xFFFF; checking instruction after branch is executed

beq $0, $0, 0x0003
lui $2, 0xFFFF
lui $1, 0xFFFE
jr $0
nop
