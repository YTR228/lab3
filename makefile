lab3: main.o sorts.o queue.o fileio.o timer.o benchmark.o
	gcc -o lab3 main.o sorts.o queue.o fileio.o timer.o
main.o: main.c sorts.h queue.h fileio.h timer.h
	gcc -c -o main.o main.c
sorts.o: sorts.c sorts.h
	gcc -c -o sorts.o sorts.c
queue.o: queue.c queue.h
	gcc -c -o queue.o queue.c
fileio.o: fileio.c fileio.h
	gcc -c -o fileio.o fileio.c
timer.o: timer.c timer.h
	gcc -c -o timer.o timer.c
benchmark.o: benchmark.c benchmark.h sorts.h queue.h fileio.h timer.h
	gcc -c -o benchmark.o benchmark.c
clean:
	rm -f *.o lab3