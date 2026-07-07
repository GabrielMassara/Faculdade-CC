.text
.globl main

main:
	# a = 3
	addi $s1, $zero, 3
	
	add $a0, $zero, $s1
	jal f
	nop
	
	add $s2, $zero, $v0
	
	j fim
	nop
	
f:
	addi $sp, $sp, -8
	sw $a0, 0($sp)
	sw $ra, 4($sp)
	
	jal soma1
	nop
	# valor de soma 1
	add $t0, $zero, $v0
	
	#restaura o a0
	lw $a0, 0($sp)
	addi $sp, $sp, 4
	
	jal dobro
	nop
	# valor de dobro
	add $t1, $zero, $v0
	
	# define o retorno
	add $v0, $t0, $t1
	
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	
	jr $ra
	nop
	
soma1:
	addi $v0, $a0, 1
	jr $ra
	nop
	
dobro:
	add $v0, $a0, $a0
	jr $ra
	nop
	
fim: