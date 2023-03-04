gcc -c count_vowels.c
gcc -c master.c

gcc count_vowels.o master.o -o count_vowels_exe
./count_vowels_exe
