.name "zork_1"
.comment "I'M ALIIIIVE_1"

l2:		st r1, 13
		ld %0, r16

live:	live %5
		zjmp %:live
