#sh
#4278233600
#3
#additional comment : both sb and lb must be working, ensure the lower byte is stored and loaded

lui $a0, 0xff00
addiu $a0, $a0, 0xaa00
lui $v1, 0xbfff
sh $a0, 2($v1)
addiu $v1, $v1, 0x2
lw $v0, 0($v1)
sh $a0, 2($v1)
addiu $v1, $v1, 0x2
lw $v0, 0($v1)
jr $0
