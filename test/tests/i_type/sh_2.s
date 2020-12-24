#sh
#4278233600
#3
#additional comment : both sb and lb must be working, ensure the lower byte is stored and loaded

lui $a0, 0xff00
addiu $a0, $a0, 0xaa00
lui $v1, 0xbfff
sh $a0, 0x2($v1)
addiu $v1, $v1, 0x2
lw $v0, 0x0($v1)
jr $0
