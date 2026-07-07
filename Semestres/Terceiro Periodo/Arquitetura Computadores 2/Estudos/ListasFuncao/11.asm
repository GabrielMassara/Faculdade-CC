.text
.globl main

main:
	addi $s1, $zero, 5
	
	add $a0, $zero, $s1
	jal positivo
	nop
	
	add $s2, $zero, $v0
	
	j fim
	nop
	
positivo:
	addi $t1, $zero, 1
	slt $t2, $a0, $t1
	
	add $v0, $zero, $zero
	
	beq $t2, $zero, maiorZero
	nop
	
	j fimFuncao
	nop
	
	maiorZero:
		addi $v0, $zero, 1
		
	fimFuncao:
		jr $ra
		nop
		
fim:
	