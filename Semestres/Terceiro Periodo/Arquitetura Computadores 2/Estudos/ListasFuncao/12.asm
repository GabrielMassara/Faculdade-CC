.text
.globl main

main:
	# j = 4
	addi $s1, $zero, 4
	
	# k = 3
	addi $s2, $zero, 3
	
	# i = mult(j,k)
	add $a0, $zero, $s1
	add $a1, $zero, $s2
	jal mult
	nop
	
	add $s0, $zero, $v0
	
	j fim
	nop
	
mult:
	# produto = 0
	add $t0, $zero, $zero
	
	inicioMult:
		# condicao do while
		slt $t1, $a1, $zero
		beq $t1, $zero, fimMult
		
		# produto = produto + mando
		add $t0, $t0, $a0
	
		# mdor = mdor - 1
		addi $t2, $zero, -1
		add $a1, $a1, $t2
		
		j inicioMult
		nop
	
	
	fimMult:
	add $v0, $zero, $t0
	jr $ra
	nop
	
fim: