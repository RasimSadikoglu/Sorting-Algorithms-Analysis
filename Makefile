CC:=g++
FLAGS:=-O3
SRCS:=src/list.cpp src/sorts.cpp src/main.cpp

bin/main: bin/ logs/ $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o bin/main

bin/:
	mkdir -p bin

logs/:
	mkdir -p logs

run: bin/main
	rm -f logs/*
	bin/main

clean:
	rm -rf bin logs