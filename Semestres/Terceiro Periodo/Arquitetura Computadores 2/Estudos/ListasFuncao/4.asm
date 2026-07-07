.text
.globl main

main:
	addi $s1, $zero, 1
	add $a0, $zero, $s1
	jal soma1
	nop
	
	#b = soma1(a)
	add $s2, $zero, $v0
	
	j fim
	nop
	
soma1:
	addi $v0, $a0, 1
	jr $ra
	nop
	
fim:
