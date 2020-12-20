#lwr
#5592337
#2
#Load the 3 least significant bytes of 0x55551123 (ie 0x551123)

ori $sp, $0, 4
lui $t0, 0x5555
ori $t0, $t0, 0x1123
sw  $t0, 0($sp)
lwr $v0, 1($sp)
jr $0

