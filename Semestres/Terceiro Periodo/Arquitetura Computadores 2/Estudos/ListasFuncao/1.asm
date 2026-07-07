.text
.globl main

main:
	jal um
	nop
	
	# a = retorno da funcao um()
	add $s1, $v0, $zero
	j fim
	nop
	
um:
	addi $v0, $zero, 1 # return 1
	jr $ra # volta para quem chamou a funcao
	nop
	
fim:

	