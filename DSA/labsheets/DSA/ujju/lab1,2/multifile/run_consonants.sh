gcc -c count_consonants.c
gcc -c master.c

gcc count_consonants.o master.o -o count_consonants_exe
./count_consonants_exe
