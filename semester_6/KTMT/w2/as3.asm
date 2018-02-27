#3
.text
	li	$s0,0x2110003d  #pseudo instruction=2 basic instructions
	li	$s1,0x2		

# Tap lenh MIP la 32 bit, ta gan' 0x21100000 vao $at (thanh ghi tam thoi)
# Sau do gan' tiep phan` 0x0000003d vao $s0 = 0x2110003d
# $s0 chay binh thuong