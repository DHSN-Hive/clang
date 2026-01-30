CC = g++

all: program.bin
	
program.bin: program.o student.o list.o element.o
	$(CC) -o program.bin program.o student.o list.o element.o

program.o: program.cpp
	$(CC) -c -o program.o program.cpp

list.o: list.cpp list.hpp
	$(CC) -c -o list.o list.cpp

element.o: element.cpp element.hpp
	$(CC) -c -o element.o element.cpp

student.o: student.cpp student.hpp
	$(CC) -c -o student.o student.cpp

clean:
	rm -rf *.bin *.o
