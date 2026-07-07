.text
.globl main

main:
	# x = 1
	addi $s1, $zero, 1
	
	# y = 2
	addi $s2, $zero, 2
	
	# chama a funcao soma passando os dois argumentos
	add $a0, $zero, $s1
	add $a1, $zero, $s2
	jal soma
	nop
	
	# z = soma(x, y)
	add $s3, $zero, $v0
	
	j fim
	nop
	
soma:
	add $v0, $a0, $a1
	jr $ra
	nop
	
fim:
