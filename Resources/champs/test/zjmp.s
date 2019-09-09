.name "zjmp"
.comment "JUMP JUMP JUMP"

		and r1, %0, r1
		or r1, %0, r1
		xor r1, %0, r1
l1:		live %1
		zjmp %65520
