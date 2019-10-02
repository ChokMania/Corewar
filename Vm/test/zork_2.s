.name "zork_2"
.comment "I'M ALIIIIVE_2"

l2:		sti r1, %:live, %1
		and r1, %10, r1

live:	live %1
		zjmp %:live
