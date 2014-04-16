# CS Tutors Make/GDB/Valgrind workshop
# Colleen Murphy

cc = g++
FLAGS=-Wall -g -c

all: main.o
	$(cc) main.o -o helloworld

main.o: main.cpp
	$(cc) $(FLAGS) main.cpp

clean:
	rm main.o helloworld
