.text
.globl main

main:
	# n = 5
	addi $s1, $zero, 5
	
	add $a0, $zero, $s1
	jal quadradoMaisDobro
	nop
	
	add $s2, $zero, $v0
	
	j fim
	nop
	
quadradoMaisDobro:
	addi $sp, $sp, -8
	sw $a0, 0($sp)
	sw $ra, 4($sp)
	
	# define o segundo argumento para mult
	add $a1, $zero, $a0
	
	jal mult
	nop
	addi $sp, $sp, -4
	sw $v0, 0($sp)
	
	# restaura o a0
	lw $a0, 4($sp)
	
	jal dobro
	nop
	
	# define a resposta
	lw $t0, 0($sp)
	add $v0, $v0, $t0
	
	# restaura o ra
	lw $ra, 8($sp)
	
	# desempilha
	addi $sp, $sp, 12
	
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
		
dobro:
	add $v0, $a0, $a0
	jr $ra
	nop
	
fim: