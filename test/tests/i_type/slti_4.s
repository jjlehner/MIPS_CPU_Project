#slti
#2
#4
.set noreorder 
.set nomacro
lui	  $v0,  0xFFFF
addiu $v0, $v0, 0xFFF0
l1:
addiu  $v0, $v0, 1
slti  $a0, $v0, 0xFFFE
bne   $a0, $0,  l1
jr $0

