.name "TEST"
.comment "I'M ALIIIIVE_2"

sti r1, 10, %:live
live: live %1
sti r1, 32769, %0
sti r1, -1, %0
sti r1, -0, %0
sti r1, 511, %0
sti r1, 512, %0
sti r1, 513, %0
sti r1, 0, %0
