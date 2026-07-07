.data
	cabeca: .space 400 #400 bytes = 100 inteiros
.text
.globl main

main:
	lui $t0, 0x1001
	
	# i=99
	addi $s0, $zero, 99
	addi $t0, $t0, 396
	
	# maior = vet[i]
	lw $s1, 0($t0)
	
do:
	# i=i-1
	addi $s0, $s0, -1
	addi $t0, $t0, -4
	
	#vet[i]
	lw $t1, 0($t0)
	
	# se o maior < vet[i]
	slt $t2, $s1, $t1
	beq $t2, $zero, continua
	
	# maior = vet[i]
	add $s1, $zero, $t1
	
continua:
	beq $s0, $zero, fim
	
	j do
	
fim:
	#vet[99] = maior
	sw $s1, 396($t0)