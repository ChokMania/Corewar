.name "zork_1"
.comment "I'M ALIIIIVE_1"

fork %12
ld %4294967294, r1
l2:		st r1, 130
		ld %1, r16

live:	live %4294967294
		zjmp %:live
