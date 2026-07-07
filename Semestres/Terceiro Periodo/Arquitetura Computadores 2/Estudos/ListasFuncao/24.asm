.data
VetA: .word 10, 20, 30, 40

.text
.globl main

main:
	lui $s0, 0x1001
	addi $s1, $zero, 2
	
	# j = VetA[i]
	sll $t0, $s1, 2
	add $t1, $s0, $t0
	lw $s2, 0($t1)
	
	# j = soma1(j)
	add $a0, $zero, $s2
	jal soma1
	nop
	add $s2, $zero, $v0
	
	# VetA[i] = j
	sw $s2, 0($t1)
	
	j fim
	nop
	
soma1:
	addi $v0, $a0, 1
	jr $ra
	nop
	
fim: