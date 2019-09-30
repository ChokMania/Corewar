while :
do
	read INPUT
	clear
	./corewar Vm/test/Bazou.cor -d $INPUT > test1
	./vm_champs/corewar Vm/test/Bazou.cor -d $INPUT > test2
	diff test1 test2
	tail -n 1 test1
	tail -n 1 test2
done