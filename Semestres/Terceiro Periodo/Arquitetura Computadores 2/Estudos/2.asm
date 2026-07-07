.data
	cabeca: .space 400 #400 bytes = 100 inteiros
.text
.globl main

main:
	lui $t0, 0x1001
	
	addi $s2, $zero, 2
	
	lw $t1, 32($t0)
	
	add $t1, $t1, $s2
	
	sw $t1, 48($t0)