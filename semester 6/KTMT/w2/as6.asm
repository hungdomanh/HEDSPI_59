#6
 .data	# DECLARE VARIABLES
X : .word 5	# Variable X, word type, init value =
Y : .word -1	# Variable Y, word type, init value =
Z : .word	# Variable Z, word type, no init value

.text	# DECLARE INSTRUCTIONS
	# Load X, Y to registers
	la	$t8, X		# Get the address of X in Data Segment
	la	$t9, Y		# Get the address of Y in Data Segment
	lw	$t1, 0($t8)	# $t1 = X
	lw	$t2, 0($t9)	# $t2 = Y
	
	# Calcuate the expression Z = 2X + Y with registers only
	add	$s0, $t1, $t1	# $s0 = $t1 + $t1 = X + X = 2X
	add	$s0, $s0, $t2	# $s0 = $s0 + $t2 = 2X + Y
	# Store result from register to variable Z
	la	$t7, Z	# Get the address of Z in Data Segment
	sw	$s0, 0($t7)	# Z = $s0 = 2X + Y

# lenh "la"  duoc bien dich theo 2 buoc: (VD: la $t8, X) 
	# gan gia tri X vao thanh ghi tam thoi ($at)
	# gan $t8 = $at
# So sanh X, Y, Z voi hang so khi bien dich lenh la
	# hang so khi bien dich lenh la luon la $at = 0x10010000
	# X = 0x10010000 , Y = 0x10010004 , Z = 0x10010008
	# Value tuong ung: X: 0x00000005 , Y: 0xffffffff , Z: 0x00000000
# Thanh ghi thay doi
	# pc = 0x00400004 , at = 0x10010000
	# pc = 0x00400008 , t8 = 0x10010000
	# pc = 0x0040000c
	# pc = 0x00400010 , t9 = 0x10010004
	# pc = 0x00400014 , t1 = 0x00000005
	# pc = 0x00400018 , t2 = 0xffffffff
	# pc = 0x0040001c , s0 = 0x0000000a
	# pc = 0x00400020 , s0 = 0x00000009
	# pc = 0x00400024
	# pc = 0x00400028 , t7 = 0x10010008
	# pc = 0x0040002c
#lw : dua gia tri X, Y vao thanh ghi
#sw: dua gia tri phep toan vao thanh ghi