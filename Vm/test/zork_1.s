.name "zork_1"
.comment "I'M ALIIIIVE_1"

ld %4294967294, r1
l2:		st r1, 130
		ld %0, r16

live:	live %4294967294
		zjmp %:live
