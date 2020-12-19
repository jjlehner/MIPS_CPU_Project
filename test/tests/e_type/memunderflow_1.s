#memory_underflow
#10
#1
#addition comment: check reg2 = 10 -> only second addiu should execute as reset starts at 0xBFC0;

jr 0xBFBE0000
#now 0xBFBF0000
addiu $2, $2, 10
#now 0xBFC00000
addiu $2, $2, 10
jr $0
nop
