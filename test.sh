rm -f test1 test2
champ="Vm/test/testmalo.s"
echo $champ
./asm $champ
champ="Vm/test/testmalo.cor"
while :
do
	read INPUT
	clear
	./corewar $champ -d $INPUT > test1
	./vm_champs/corewar $champ -d $INPUT > test2
	diff test1 test2 | cat -e
	echo "\ncycle $INPUT"
done
