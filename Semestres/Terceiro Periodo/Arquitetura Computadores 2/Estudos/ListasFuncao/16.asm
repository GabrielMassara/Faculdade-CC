.text
.globl main

main:
	jal tres
	nop
	
	add $s1, $zero, $v0
	
	j fim
	nop
	
tres:
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	
	jal dois
	nop
	
	addi $v0, $v0, 1
	
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	jr $ra
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