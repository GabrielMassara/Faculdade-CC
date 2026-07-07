.text
.globl main

main:
	# x = 1
	addi $s1, $zero, 1
	
	# y = 2
	addi $s2, $zero, 2
	
	# primeira chamada (Z)
	add $a0, $zero, $s1
	add $a1, $zero, $s2
	jal soma
	nop
	
	add $s3, $zero, $v0
	# ---------------
	
	# segunda chamada (K)
	add $a0, $zero, $s1
	add $a1, $zero, $s1
	jal soma
	nop
	
	add $s4, $zero, $v0
	# ---------------
	
	# terceira chamada (M)
	add $a0, $zero, $s2
	add $a1, $zero, $s2
	jal soma
	nop
	
	add $s5, $zero, $v0
	# ---------------
	
	# quarta chamada (X)
	add $a0, $zero, $s4
	add $a1, $zero, $s5
	jal soma
	nop
	
	add $s1, $zero, $v0
	# ---------------
	
	j fim
	nop
	
soma:
	add $v0, $a0, $a1
	jr $ra
	nop
	
fim: