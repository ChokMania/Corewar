while :
do
	read INPUT
	clear
	./corewar vm_champs/champs/championships/2017/gnebie/ultima.cor vm/test/zork_1.cor -d $INPUT > test1
	./vm_champs/corewar vm_champs/champs/championships/2017/gnebie/ultima.cor vm/test/zork_1.cor -d $INPUT > test2
	diff test1 test2
	tail -n 1 test1
	tail -n 1 test2
done