.text
.globl main

main:
	# n = 5
	addi $s1, $zero, 5
	
	add $a0, $zero, $s1
	jal somatorio
	nop
	
	add $s2, $zero, $v0
	
	j fim
	nop
	
somatorio:
	# soma = 0
	add $t2, $zero, $zero
	
	# t1 = 1
	addi $t1, $zero, 1
	
	condicaoLoop:
		slt $t0, $a0, $t1
		bne $t0, $zero, fimSomatorio
	loop:
		# soma = soma + n
		add $t2, $t2, $a0
		
		# n = n - 1
		sub $a0, $a0, $t1
		
		j condicaoLoop
		nop
	
	fimSomatorio:
		add $v0, $zero, $t2
		jr $ra
		nop
		
fim: