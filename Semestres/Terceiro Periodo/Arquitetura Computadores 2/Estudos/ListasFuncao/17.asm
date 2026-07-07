.text
.globl main

main:
	# a = 1
	addi $s1, $zero, 1
	
	add $a0, $zero, $s1
	jal soma3
	nop
	
	# b = soma3(a)
	add $s2, $zero, $v0
	
	# a = a + b
	add $s1, $s1, $s2
	
	j fim
	nop
	
soma3:
	addi $sp, $sp, -4
	sw $ra, 0($sp)

	# y+1 como argumento
	addi $a0, $a0, 1
	
	jal soma1
	nop
	
	# return soma1(y + 1) + 1
	addi $v0, $v0, 1
	
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	
	jr $ra
	nop
	
soma1:
	addi $v0, $a0, 1
	jr $ra
	nop
		
fim: