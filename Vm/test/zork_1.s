.name "zork_1"
.comment "I'M ALIIIIVE_1"

l2:		sti r1, %:live, %1
		and %1, %:live, r2

live:	live %1
		zjmp %:live
