.text
.globl main

main:
	addi $s1, $zero, 2
	addi $s2, $zero, 3
	addi $s3, $zero, 4
	
	add $a0, $zero, $s1
	add $a1, $zero, $s2
	add $a2, $zero, $s3
	jal soma3valores
	nop
	
	add $s4, $zero, $v0
	
	j fim
	nop
	
soma3valores:
	add $v0, $a0, $a1
	add $v0, $v0, $a2
	jr $ra
	nop
	
fim: