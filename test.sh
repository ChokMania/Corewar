rm -f test1 test2
while :
do
	read INPUT
	clear
	./corewar Vm/test/Bazou_test.cor -d $INPUT > test1
	./vm_champs/corewar Vm/test/Bazou_test.cor -d $INPUT > test2
	diff test1 test2 | cat -e
	echo "\ncycle $INPUT"
done
