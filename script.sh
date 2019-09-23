#!/bin/zsh

remove=1

test_file_error () {
	echo "Test Numero : $i"
	echo "\033[33mNotre ASM\033[0m"
	./asm $fichier
	name=${fichier%.s*}
	name+=.cor
	if [ -e $name ]; then fail="KO"; else fail=""; fi
	if [ $remove -eq 1 ]; then rm -f $name; fi
	echo "\033[33mASM Ressources\033[0m"
	./vm_champs/asm $fichier
	if [ $remove -eq 1 ]; then rm -f $name; fi
	if [ "$fail" != "" ];
	then
		printf "%-70s\033[31mKO\033[00m\n";
		read -p "Appuez sur Return pour continuer ou 0 pour quitter..." ZERO
		if [ "$ZERO" == "0" ]
		then
			clear
			exit;
		fi
	else
		printf "%-70s\033[32mOK\033[00m\n";
	fi;
	echo
}

test_file_valid () {
	echo "Test Numero : $j"
	./asm $fichier > /dev/null
	name=${fichier%.s*}
	name+=.cor
	hexdump -C $name > notre-cor
	if [ $remove -eq 1 ]; then rm -f $name; fi
	./vm_champs/asm $fichier > /dev/null
	name=${fichier%.s*}
	name+=.cor
	hexdump -C $name > vrai-cor
	if [ $remove -eq 1 ]; then rm -f $name; fi
	DIFF=$(diff notre-cor vrai-cor)
	if [ "$DIFF" != "" ]
	then
		mkdir -p error_test 2> /dev/null || true
		printf "%-70s\033[31mKO\n" $fichier
		dif="error_test/$j-diff"
		diff notre-cor vrai-cor > $dif
		mv notre-cor error_test/"$j-notre"
		mv vrai-cor error_test/"$j-vrai"
		echo "Création du fichier $dif\033[00m"
		read -p "Appuez sur Return pour continuer ou 0 pour quitter..." ZERO
		if [ "$ZERO" == "0" ]
		then
			clear
			exit;
		fi
		printf "\n"
	else
		rm -Rf notre-cor vrai-cor
		printf "%-70s\033[32mOK\033[00m\n\n" $fichier
	fi
}

clear
rm -Rf ./error_test
while :
do
	clear
	echo " ---------------------------------"
	echo "| 1.Test_Error 3.Test_Valide_2 |\n
		| 2.Test_Valid 0.Exit |" | column -t
	echo " ---------------------------------"
	read INPUT
	case $INPUT in
				1)
					clear
					i=1
					make -sj
					for fichier in ./vm_champs/error/*.s
					do
						test_file_error
						i=$((i+1))
					done
					read -p "Appuez sur Return pour continuer...";;
				2)
					clear
					j=1
					make -sj
					for fichier in ./vm_champs/valid/*.s
					do
						test_file_valid
						j=$((j+1))
					done 
					read -p "Appuez sur Return pour continuer...";;
				3)
					clear
					j=1
					make -sj
					for fichier in ./vm_champs/valid2/*.s
					do
						test_file_valid
						j=$((j+1))
					done 
					read -p "Appuez sur Return pour continuer...";;
				0)
					break ;;
	esac
done
clear



