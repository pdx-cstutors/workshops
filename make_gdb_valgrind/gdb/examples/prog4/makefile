# CS Tutors Make/GDB/Valgrind workshop
# Kendall Stewart

CC = g++
FLAGS = -g -c -Wall

all: tree.o main.o
	$(CC) -g *.o

tree.o: tree.cpp tree.h
	$(CC) $(FLAGS) tree.cpp

main.o: main.cpp tree.h
	$(CC) $(FLAGS) main.cpp

clean:
	rm tree.o main.o a.out
