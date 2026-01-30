#include<iostream> // c++: cin, cout
#include<stdio.h> // c: printf, scanf, fopen
#include<string.h> // c: strcpy, memcpy

using namespace std;

int main()
{
	char *s = NULL;

	// Speicher reservieren mit C++ Funktion
	s = new char[16];

	// Speicher beschreiben mit C Funktion
	strcpy(s, "Mustermann");

	// Ausgabe mit C und C++ Funktionen
	printf("Der Wert für s in c ist %s\n", s);
	cout << "Der Wert für s in c++ ist " << s << endl;

	// Speicher löschen mit C++ Funktion
	delete [] s;
	s = NULL;

	return 0;
}


