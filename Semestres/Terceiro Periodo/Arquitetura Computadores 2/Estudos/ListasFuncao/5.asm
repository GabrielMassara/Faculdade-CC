.text
.globl main

main:
	# a = 4
	addi $s1, $zero, 4
	
	add $a0, $zero, $s1
	jal dobro
	nop
	
	add $s2, $zero, $v0
	
	j fim
	nop
	
dobro:
	add $v0, $a0, $a0
	jr $ra
	nop
			
fim:
