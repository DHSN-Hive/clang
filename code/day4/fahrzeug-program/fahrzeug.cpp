#include "fahrzeug.hpp"

#ifndef FAHRZEUG_CPP
#define FAHRZEUG_CPP

using namespace std;

fahrzeug::fahrzeug()
{
	cout << "fahrzeug()" << endl;
	this->set_Geschwindigkeit(0);
	this->set_Alter(0);
}

fahrzeug::fahrzeug(int g, int a)
{
	cout << "fahrzeug(" << g << ", " << a << ")" << endl;
	this->set_Geschwindigkeit(g);
	this->set_Alter(a);
}

fahrzeug::~fahrzeug()
{
	cout << "~fahrzeug()" << endl;
	this->geschwindigkeit = 0;
	this->alter = 0;
}

void fahrzeug::set_Geschwindigkeit(int g)
{
	this->geschwindigkeit = g;
}

int fahrzeug::get_Geschwindigkeit()
{
	return this->geschwindigkeit;
}

void fahrzeug::set_Alter(int a)
{
	this->alter = a;
}

int fahrzeug::get_Alter()
{
	return this->alter;
}

#endif
