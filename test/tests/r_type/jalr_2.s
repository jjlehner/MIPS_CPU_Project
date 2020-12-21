#jalr
#500
#2

.set noreorder 
.set nomacro

l1:
lui   $t0, 0xbfc0         #bfc0 0000
ori   $t0, $t0, 0x001C    #bfc0 0004
jalr  $t0                 #bfc0 0008
addiu $ra, $ra, 0x4       #bfc0 000C
j l1                      #bfc0 0010
jr $0                     #bfc0 0014
nop                       #bfc0 0018
nop                       #bfc0 001C
addiu $v0, $v0, 100       #bfc0 0020
addiu $v0, $v0, 100       #bfc0 0024
addiu $v0, $v0, 100       #bfc0 0028
addiu $v0, $v0, 100       #bfc0 002C
addiu $v0, $v0, 100       #bfc0 0030
jr $ra                    #bfc0 0034
nop                       #bfc0 0038

