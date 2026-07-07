.data
.word 2 4 6 8

.text
.globl main

main:
	lui $s0, 0x1001
	
	# i = 0
	add $s1, $zero, $zero
	
	# k = 3
	addi $s2, $zero, 3
	
	# t0 = 4
	addi $t0, $zero, 4
	
loop:
	slt $t1, $s1, $t0
	beq $t1, $zero, fim
	
	# normaliza o indice para o mips
	sll $t2, $s1, 2
	add $t3, $s0, $t2 # anda as posicoes do vetor
	
	# pega o elemento do vetor na posicao de i
	lw $t4, 0($t3)
	
	add $a0, $zero, $t4
	add $a1, $zero, $s2
	jal mult
	nop
	
	# salva no vetor na posicao i
	sw $v0, 0($t3)
	
	addi $s1, $s1, 1
	
	j loop
	nop
	
mult:
	# prod = 0
	add $t5, $zero, $zero
	
	# t1 guarda o valor 1 fixo
	addi $t6, $zero, 1
	
	loopMult:
		slt $t7, $a1, $t6
		bne $t7, $zero, fimMult
		nop
		
		# prod = prod + m
		add $t5, $t5, $a0
		# n = n - 1
		addi $a1, $a1, -1
		
		j loopMult
		nop
		
	fimMult:
		add $v0, $zero, $t5
		jr $ra
		nop
		
fim:
	
