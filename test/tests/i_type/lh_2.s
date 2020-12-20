#lh
#531
#2
# Store then load lower half of a number

lui $t0, 0x213
ori $t0, $t0, 0x8712
ori $sp, $0, 12
sw  $t0, 0($sp)
lh  $v0, 2($sp)
jr  $0

