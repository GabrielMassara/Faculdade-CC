.data
	cabeca: .space 404 #404 bytes = 101 inteiros
.text
.globl main

main:
	lui $t0, 0x1001
	
	# i = 0
	add $t1, $zero, $zero
	
	# acumulador da soma
	add $t2, $zero, $zero
	
	addi $t4, $zero, 100
do:
	lw $t3, 0($t0)
	
	add $t2, $t2, $t3
	
	addi $t0, $t0, 4
	addi $t1, $t1, 1
	
	beq $t1, $t4, fim
	
	j do
	
fim:
	sw $t2, 0($t0)