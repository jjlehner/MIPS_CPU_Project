#lb
#4294967213
#4

lui $t0, 0x0123
ori $t0, $0, 0xADFF
ori $t1, $0, 0x0BB4
sw  $t0, 0($t1)
lb  $v0, 1($t1)
jr $0

