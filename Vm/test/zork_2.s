.name "zork_2"
.comment "I'M ALIIIIVE_2"

l2:		sti r1, %:live, %1
		and r1, %10, r1
		ld %68, r1
		sti r1, %:live, %1
live:	live %1
		aff r1
		zjmp %:live
