CC=g++
FLAGS=-c -Wall -Wextra -Wpedantic

output: main.o list.o sorts.o
	$(CC) main.o list.o sorts.o -o output

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

list.o: list.h list.cpp
	$(CC) $(FLAGS) list.cpp

sorts.o: sorts.h sorts.cpp
	$(CC) $(FLAGS) sorts.cpp

run: output
	rm -rf *sort.txt
	./output

clean:
	rm -rf *.o *.txt output*
