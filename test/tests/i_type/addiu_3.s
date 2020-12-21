#addiu
#4294901760
#3

.set noreorder 
.set nomacro

lui $8, 0xFFFF
addiu $2, $8, 0x0
jr $0
nop

