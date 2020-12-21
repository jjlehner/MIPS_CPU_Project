#lb
#109
#3

lui $t0, 0xBFCC
lui $t1, 0x556D
ori $t1, 0x2234
sw  $t1, 0($t0)
lb  $v0, 2($t0)
jr $0

