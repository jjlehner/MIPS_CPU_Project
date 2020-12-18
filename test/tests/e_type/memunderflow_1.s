#memory_underflow
#10
#1
#addition comment: check reg1 = 10 -> only second addiu should execute as reset starts at 0xBFC0;

jr 0xBFBE
#now 0xBFBF
addiu $1, $1, 10
#now 0xBFC0
addiu $1, $1, 10
jr $0
nop
