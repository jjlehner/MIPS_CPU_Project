#lb 
#4294967294
#1
#additional comment : both sb and lb must be working
#none
	lui $t0, 0xbfcc
	lui $t1, 0x1000
	ori $t1, $t1, 0x00FE
	sw $t1, 0($t0)
	lb $v0, 0($t0)
	jr $0
	nop

