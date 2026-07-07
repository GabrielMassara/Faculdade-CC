.text
.globl main

main:
    addi $s1, $zero, 0

    jal dois
    nop

    add $s1, $v0, $zero

    j fim
    nop


dois:
    addi $sp, $sp, -4
    sw $ra, 0($sp)

    jal um
    nop

    addi $v0, $v0, 1
	
    lw $ra, 0($sp)
    addi $sp, $sp, 4

    jr $ra
    nop


um:
    addi $v0, $zero, 1
    jr $ra
    nop


fim:
    addi $v0, $zero, 10
    syscall