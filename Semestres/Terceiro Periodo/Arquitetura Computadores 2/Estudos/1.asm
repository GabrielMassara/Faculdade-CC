.data

.text
.globl main

main:
	# s0 = a
	addi $s0, $zero, 10
	
	#s1 = b
	addi $s1, $zero, -1
	
	addi $s0, $s0, 1
	
	add $s2, $s0, $s1