rm -f test1 test2

champ1="Vm/test/testmalo.s"
./asm $champ1
champ1="Vm/test/testmalo.cor"

champ2="Vm/test/testmalo.s"
./asm $champ2
champ2="Vm/test/testmalo.cor"

champ3="Vm/test/testmalo.s"
./asm $champ3
champ3="Vm/test/testmalo.cor"

champ4="Vm/test/testmalo.s"
./asm $champ4
champ4="Vm/test/testmalo.cor"

champ5="Vm/test/testmalo.s"
./asm $champ5
champ5="Vm/test/testmalo.cor"

champ6="Vm/test/testmalo.s"
./asm $champ6
champ6="Vm/test/testmalo.cor"

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
	
	./corewar $champ4 -d $INPUT > test1
	./vm_champs/corewar $champ4 -d $INPUT > test2
	diff test1 test2 | cat -e
	echo "\$$champ4 OK"
	
	./corewar $champ5 -d $INPUT > test1
	./vm_champs/corewar $champ5 -d $INPUT > test2
	diff test1 test2 | cat -e
	echo "\$$champ5 OK"
	
	./corewar $champ6 -d $INPUT > test1
	./vm_champs/corewar $champ6 -d $INPUT > test2
	diff test1 test2 | cat -e
	echo "\$$champ6 OK"
done
