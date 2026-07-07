.text
.globl main

main:
	# a = 3
	addi $s1, $zero, 3
	
	add $a0, $zero, $s1
	jal soma1
	nop
	add $s2, $zero, $v0
	
	add $a0, $zero, $s1
	add $a1, $zero, $s2
	jal soma
	nop
	add $s3, $zero, $v0
	
	j fim
	nop
	
soma1:
	addi $v0, $a0, 1
	jr $ra
	nop
	
soma:
	add $v0, $a0, $a1
	jr $ra
	nop

fim: