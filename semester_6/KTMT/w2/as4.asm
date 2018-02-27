#4
.text
	# Assign X, Y
	addi $t1, $zero, 5	# X = $t1 = ?
	addi $t2, $zero, -1	# Y = $t2 = ?
	# Expression Z = 2X + Y
	add $s0, $t1, $t1	# $s0 = $t1 + $t2 = X + X = 2X
	add $s0, $s0, $t2	# $s0 = $

# Thanh ghi thay doi
	# pc = 0x00400004 , t1 = 0x00000005
	# pc = 0x00400008 , t2 = 0xffffffff
 	# pc = 0x0040000c , s0 = 0x0000000a
 	# pc = 0x00400010 , s0 = 0x00000009
# Diem tuong dong giua hop ngu va ma may: Deu phan vung tap lenh
# Giong voi khuon mau cua kieu lenh R