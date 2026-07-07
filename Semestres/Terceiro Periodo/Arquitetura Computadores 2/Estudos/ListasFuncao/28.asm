.data
vetA: .word 1 2 3 4

.text
.globl main

main:
	# base vetor
	lui $s0, 0x1001
	
	# i = 0
	add $s1, $zero, $zero
	
	# t0 = 4
	addi $t0, $zero, 4
	
loop:
	slt $t1, $s1, $t0
	beq $t1, $zero, fim
	
	sll $t2, $s1, 2
	add $t3, $s0, $t2 # posicao atual do vetor
	
	lw $t4, 0($t3)
	add $a0, $zero, $t4
	add $a1, $zero, $s1
	
	jal SumSquare
	nop
	
	sw $v0, 0($t3)
	
	addi $s1, $s1, 1
	
	j loop
	nop
	
SumSquare:
	addi $sp, $sp, -12
	sw $a1, 0($sp)
	sw $a0, 4($sp)
	sw $ra, 8($sp)
	
	add $a1, $zero, $a0
	jal mult
	nop
	
	lw $a1, 0($sp)
	
	add $v0, $v0, $a1
	
	lw $ra, 8($sp)
	addi $sp, $sp, 12
	
	jr $ra
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