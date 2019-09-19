echo "Operateurs en fin de ligne :\n"
grep -r --include \*.c -H "[-&|?:%]$" $@
grep -r --include \*.c -H -e '[^/]\*$' $@
echo "Norminette :\n"
norminette `find . -type f -name '*.c' -o -name '*.h'`