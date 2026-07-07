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
	# PODERIA USAR UMA ALOCACAO UNICA COM -8
	# --- EXEMPLO ---
	# addi $sp, $sp, -8
	# sw $a0, 0($sp)
	# sw $ra, 4($sp)
	# --- FIM EXEMPLO ---

	addi $sp, $sp, -4
	sw $ra, 0($sp)
	
	addi $sp, $sp, -4
	sw $a0, 0($sp)

	# y+1 como argumento
	addi $a0, $a0, 1
	
	jal soma1
	nop
	
	# volta com o a0
	lw $a0, 0($sp)
	addi $sp, $sp, 4
	# return soma1(y + 1) + y
	add $v0, $v0, $a0
	
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	
	jr $ra
	nop
	
soma1:
	addi $v0, $a0, 1
	jr $ra
	nop
		
fim: