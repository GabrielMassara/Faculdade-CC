.text
.globl main

main:
	addi $s1, $zero, 7
	
	# primeira chamada
	add $a0, $zero, $s1
	jal soma1
	nop
	
	add $s1, $zero, $v0
	#---
	
	# segunda chamada
	add $a0, $zero, $s1
	jal soma1
	nop
	
	add $s1, $zero, $v0
	#---
	
	j fim
	nop
	
soma1:
	addi $v0, $a0, 1
	jr $ra
	nop
	
fim: