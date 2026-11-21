# lab2: main.o applicants.o
# 	gcc -o lab2 main.o applicants.o
# main.o: main.c applicants.h
# 	gcc -c -o main.o main.c
# applicants.o: applicants.c applicants.h
# 	gcc -c -o applicants.o applicants.c
# clean:
# 	rm -f *.o lab2



lab3: main.o sorts.o queue.o
	gcc -o lab3 main.o sorts.o queue.o
main.o: main.c sorts.h queue.h
	gcc -c -o main.o main.c
sorts.o: sorts.c sorts.h
	gcc -c -o sorts.o sorts.c
queue.o: queue.c queue.h
	gcc -c -o queue.o queue.c
clean:
	rm -f *.o lab3