#5
.text
	# Assign X, Y
	addi $t1, $zero, 4	# X = $t1 = ?
	addi $t2, $zero, 5	# Y = $t2 = ?
	# Expression Z = 3*XY
	mul	$s0, $t1, $t2	# HI-LO = $t1 * $t2 = X * Y ; $s0 = LO
	mul	$s0, $s0, 3	# $s0 = $s0 * 3 = 3 * X * Y
	# Z' = Z
	mflo $s1

# Lenh mul $s0, $s0, 3 duoc phan thanh 2 lenh do gia tri vuot qua 16-bit nen phai luu vao thanh ghi tam thoi truoc ($at)
# Thanh ghi thay doi
	# pc = 0x00400004 , t1 = 0x00000004
	# pc = 0x00400008 , t1 = 0x00000005
	# pc = 0x0040000c , s0 = 0x00000014 , lo = 0x00000014
	# pc = 0x00400010 , at = 0x00000003
	# pc = 0x00400014 , s0 = 0x0000003c , lo = 0x0000003c
	# pc = 0x00400018 , s1 = 0x0000003c , lo = 0x00000014