.text
.globl main

main:
	jal um
	nop
	
	add $s1, $zero, $v0	
	
	jal dois
	nop
	
	add $s2, $zero, $v0
	
	add $s3, $s1, $s2
	
	j fim
	nop
	
um:
	addi $v0, $zero, 1
	jr $ra
	nop
	
dois:
	addi $v0, $zero, 2
	jr $ra
	nop
	
fim: