.data
vetA: .word 1 2 3 4 5

.text
.globl main

main:
	lui $s0, 0x1001
	# i = 0
	add $s1, $zero, $zero
	
	# total = 0
	add $s2, $zero, $zero
	
	# t1 = 5
	addi $t1, $zero, 5
	
loop:
	slt $t0, $s1, $t1
	beq $t0, $zero, fim
	
	# t2 = indice * 4
	sll $t2, $s1, 2
	# anda no vetor conforme a posicao do indice
	add $t3, $s0, $t2
	
	add $a0, $zero, $s2
	# pega o valor do elemento do vetor
	lw $a1, 0($t3)
	jal soma
	nop
	
	# incrementa o total
	add $s2, $zero, $v0
	
	# incrementa 1 no indice
	addi $s1, $s1, 1
	
	j loop
	nop	
	
soma:
	add $v0, $a0, $a1
	jr $ra
	nop
	
fim: