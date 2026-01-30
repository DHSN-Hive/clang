CC = /usr/bin/g++

all: program.bin

program.bin: program.o pkw.o fahrzeug.o
	$(CC) -o program.bin program.o pkw.o fahrzeug.o

program.o: program.cpp
	$(CC) -c -o program.o program.cpp

pkw.o: pkw.hpp pkw.cpp
	$(CC) -c -o pkw.o pkw.cpp

fahrzeug.o: fahrzeug.hpp fahrzeug.cpp
	$(CC) -c -o fahrzeug.o fahrzeug.cpp

clean:
	rm -rf *.o *.bin
