# CS Tutors Make/GDB/Valgrind workshop
# Colleen Murphy

all: main.o hello.o
	g++ *.o -o helloworld

hello.o: hello.cpp hello.h
	g++ -c hello.cpp
 
main.o: main.cpp hello.h
	g++ -c main.cpp

clean:
	rm *.o helloworld
