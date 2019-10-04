rm -f test1 test2

champ1="Vm/test/testmalo.s"
./asm $champ1
champ1="Vm/test/testmalo.cor"

champ2="Vm/test/Bazou_test.s"
./asm $champ2
champ2="Vm/test/Bazou_test.cor"

champ3="vm_champs/champs/examples/helltrain.s"
./asm $champ3
champ3="vm_champs/champs/examples/helltrain.cor"

while :
do
	read INPUT
	clear

	./corewar $champ1 -d $INPUT > test1
	./vm_champs/corewar $champ1 -d $INPUT > test2
	diff test1 test2 | cat -e
	echo "\$$champ1 OK"

	./corewar $champ2 -d $INPUT > test1
	./vm_champs/corewar $champ2 -d $INPUT > test2
	diff test1 test2 | cat -e
	echo "\$$champ2 OK"
	
	./corewar $champ3 -d $INPUT > test1
	./vm_champs/corewar $champ3 -d $INPUT > test2
	diff test1 test2 | cat -e
	echo "\$$champ3 OK"

done
