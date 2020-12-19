#fizz_buzz
#233168
#1
#addition comment: fizz buzz checks if reg 2 = 233168

addi $v0, $0
 addi $t0, $0
 addi $t8, $0, 3
 addi $t9, $0, 5
start: addi $t0, $t0, 0
 ble $t0, 1000, 2
 jr $ra
 divu $t0, $t8
 mfhi $t1
 beqz $t1, 4
 divu $t0, $t9
 mfhi $t1
 bnez $t1, 1
 addu $v0, $v0, $t0
 j start
jr $0
nop
