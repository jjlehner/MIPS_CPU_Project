#xori
#92
#1
#Immediate Exclusive or of 0b00000011 and 0b01011111 => 0b01011100

addi $v0, $zero, 0x3
xori $v0, $v0, 0x5F
jr $zero
