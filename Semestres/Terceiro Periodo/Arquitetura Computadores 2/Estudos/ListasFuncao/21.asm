.text
.globl main

main:
	# a = 4
	addi $s1, $zero, 4
	
	# b = 3
	addi $s2, $zero, 3
	
	# define os argumentos
	add $a0, $zero, $s1
	add $a1, $zero, $s2
	
	jal produtoMaisSoma
	nop
	
	add $s3, $zero, $v0
	
	j fim
	nop
	
produtoMaisSoma:
	addi $sp, $sp, -12
	sw $ra, 8($sp)
	sw $a1, 4($sp)
	sw $a0, 0($sp)
	
	jal mult
	nop
	
	# salva a resposta da chamada de mult
	addi $sp, $sp, -4
	sw $v0, 0($sp)
	
	# pega novamente os argumentos
	lw $a0, 4($sp)
	lw $a1, 8($sp)
	
	jal soma
	nop
	
	lw $t0, 0($sp)
	add $v0, $v0, $t0
	
	# restaura o ra
	lw $ra, 12($sp)
	
	# desaloca o espaco
	addi $sp, $sp, 16
	
	jr $ra
	nop
	
mult:
	# prod = 0
	add $t0, $zero, $zero
	
	# t1 guarda o valor 1 fixo
	addi $t1, $zero, 1
	
	loop:
		slt $t2, $a1, $t1
		bne $t2, $zero, fimMult
		nop
		
		# prod = prod + m
		add $t0, $t0, $a0
		# n = n - 1
		addi $a1, $a1, -1
		
		j loop
		nop
		
	fimMult:
		add $v0, $zero, $t0
		jr $ra
		nop
		
soma:
	add $v0, $a0, $a1
	jr $ra
	nop
	
fim: