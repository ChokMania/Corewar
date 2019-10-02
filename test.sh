rm -f test1 test2
while :
do
	read INPUT
	clear
	./corewar vm_champs/champs/championships/2017/gnebie/ultima.cor -d $INPUT > test1
	./vm_champs/corewar vm_champs/champs/championships/2017/gnebie/ultima.cor -d $INPUT > test2
	diff test1 test2 | cat -e
	tail -n 1 test1 | cat -e
	tail -n 1 test2 | cat -e
done