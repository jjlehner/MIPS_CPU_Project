#sw
#255
#2

ori   $t1, $0, 0x55     #bfc00000
lui   $t2, 0xbfc0       #bfc00004
ori   $t2, $t2, 0x0030  #bfc00008
lui   $t0, 0x0129       #bfc0000C
ori   $t0, $t0, 0x4021  #bfc00010
sw    $t0, 0($t2)       #bfc00014
lui   $t3, 0x0128       #bfc00018
ori   $t3, $t3, 0x1021  #bfc0001C
sw    $t3, 4($t2)       #bfc00020
ori   $t4, $0, 8        #bfc00024
sw    $t4, 8($t2)       #bfc00028

