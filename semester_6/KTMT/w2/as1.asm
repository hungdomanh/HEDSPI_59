#1
.text
	addi $s0, $zero, 0x3007		# $s0 = 0 + 0x3007 = 0x3007; I-type
#	addi	$s0, $zero, 0x2110003d	
	add	$s0, $zero, $0		# $s0 = 0 + 0 = 0	   ; R-type

#Case 1		$s0, $zero, 0x3007	
	# pc = 0x00400004 , s0 = 0x00003007
	# pc = 0x00400008 , s0 = 0x00000000

#Case 2		$s0, $zero, 0x2110003d	
	# gia tri duoc gan vao $at (thanh ghi tam thoi) truoc', sau do duoc gan vao $s0
	# Cac byte dau tien trung voi' cot Code trong Text Segment
