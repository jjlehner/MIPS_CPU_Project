#fibonacci
#5
#1
#addition comment: check reg? = 5 -> fibonnaci recursion0; input = 5;


fib(int):
        addiu   $sp,$sp,-40
        sw      $31,36($sp)
        sw      $fp,32($sp)
        sw      $16,28($sp)
        move    $fp,$sp
        sw      $4,40($fp)
        lw      $2,40($fp)
        nop
        bne     $2,$0,$L2
        nop

        move    $2,$0
        b       $L3
        nop

$L2:
        lw      $3,40($fp)
        li      $2,1                        # 0x1
        bne     $3,$2,$L4
        nop

        li      $2,1                        # 0x1
        b       $L3
        nop

$L4:
        lw      $2,40($fp)
        nop
        addiu   $2,$2,-1
        move    $4,$2
        jal     fib(int)
        nop

        move    $16,$2
        lw      $2,40($fp)
        nop
        addiu   $2,$2,-2
        move    $4,$2
        jal     fib(int)
        nop

        addu    $2,$16,$2
$L3:
        move    $sp,$fp
        lw      $31,36($sp)
        lw      $fp,32($sp)
        lw      $16,28($sp)
        addiu   $sp,$sp,40
        j       $31
        nop

main:
        addiu   $sp,$sp,-40
        sw      $31,36($sp)
        sw      $fp,32($sp)
        move    $fp,$sp
        li      $4,5                        # 0x5
        jal     fib(int)
        nop

        sw      $2,24($fp)
        move    $2,$0
        move    $sp,$fp
        lw      $31,36($sp)
        lw      $fp,32($sp)
        addiu   $sp,$sp,40
        j       $31
        nop
