.text
.globl main

main:
	# a = 2
	addi $s1, $zero, 2
	
	# b = 3
	addi $s2, $zero, 3
	
	add $a0, $zero, $s1
	add $a1, $zero, $s2
	jal SumSquare
	nop
	
	add $s3, $zero, $v0
	
	j fim
	nop
	
SumSquare:
	addi $sp, $sp, -8
	sw $a1, 0($sp)
	sw $ra, 4($sp)
	
	add $a1, $zero, $a0
	jal mult
	nop
	
	# restaura o a1 dessa funcao
	lw $a1, 0($sp)
	addi $sp, $sp, 4
	
	# define a resposta da funcao
	add $v0, $v0, $a1
	
	# restaura o ra dessa funcao
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	
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
		
fim:
		