rm -f test1 test2
while :
do
	read INPUT
	clear
	./corewar Vm/test/cheh.cor vm_champs/champs/examples/helltrain.cor -d $INPUT > test1
	./vm_champs/corewar Vm/test/cheh.cor vm_champs/champs/examples/helltrain.cor -d $INPUT > test2
	diff test1 test2 | cat -e
	echo "\ncycle $INPUT"
done