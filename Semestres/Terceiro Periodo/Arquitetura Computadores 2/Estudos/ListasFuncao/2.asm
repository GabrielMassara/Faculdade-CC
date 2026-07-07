.text
.globl main

main:
	jal zero
	nop
	
	add $s1, $zero, $v0
	
	addi $s1, $s1, 5
	
	j fim
	nop

zero:
	add $v0, $zero, $zero
	jr $ra
	nop
	
fim: