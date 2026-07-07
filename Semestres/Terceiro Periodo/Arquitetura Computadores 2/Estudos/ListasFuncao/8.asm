.text
.globl main

main:
	# x = 10
	addi $s1, $zero, 10
	
	# y = 4
	addi $s2, $zero, 4
	
	add $a0, $zero, $s1
	add $a1, $zero, $s2
	jal subtrai
	nop
	
	add $s3, $zero, $v0
	
	j fim
	nop
	
subtrai:
	sub $v0, $a0, $a1
	jr $ra
	nop
	
fim: