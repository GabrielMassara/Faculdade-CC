.text
.globl main

main:
	jal dois
	nop
	addi $s1, $v0, 1
	
	j fim
	nop
	
dois:
	# reservo espaco na pilha (StackPointer)
	addi $sp, $sp, -4
	
	# salva o valor de ra na pilha
	sw $ra, 0($sp)

	jal um
	nop
	addi $v0, $v0, 1
	
	# carrega o ra novamente
	lw $ra, 0($sp)
	
	# desaloca o elemento da pilha
	addi $sp, $sp, 4
	
	jr $ra
	nop
	
um:
	addi $v0, $zero, 1
	jr $ra
	nop
	
fim: