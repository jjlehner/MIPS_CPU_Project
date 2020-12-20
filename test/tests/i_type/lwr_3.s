#lwr
#14605995
#3

ori $sp, $0, 0x4
lui $t0, 0xdede
ori $t0, $t0, 0xabab
sw  $t0, 0($sp)
sw  $t0, 4($sp)
sw  $t0, 8($sp)
sw  $t0, 12($sp)
sw  $t0, 16($sp)
sw  $t0, 20($sp)
lwr $v0, 9($sp)
jr  $0

