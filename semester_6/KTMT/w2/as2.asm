#2
.text
	lui $s0,0x2110		#put upper half of pattern in $s0
	ori $s0,0x003d		#put lower half of pattern in $s0
	
# Thanh ghi thay doi
	# pc = 0x00400004 , s0 = 0x21100000
	# pc = 0x00400008 , s0 = 0x2110003d