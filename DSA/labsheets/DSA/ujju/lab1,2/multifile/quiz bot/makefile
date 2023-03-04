setA :  setA_exe
	./setA_exe

setA_exe :  setA.o quiz.o
	gcc -o setA_exe setA.o quiz.o

setA.o :
	gcc -c setA.c

quiz.o :
	gcc -c quiz.c

clean : 
	rm -f *.o
	rm setA_exe
