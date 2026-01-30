#include "pkw.hpp"

#ifndef PWK_HPP
#define PKW_CPP

using namespace std;

pkw::pkw()
{
	cout << "pkw()" << endl;
	this->set_Achsen(0);
}

pkw::pkw(int g, int al, int ac) : fahrzeug(g, al)
{
	cout << "pkw(" << g << ", " << al << ", " << ac << ")" << endl;
	this->set_Achsen(ac);
}

pkw::~pkw()
{
	this->achsen = 0;
}

void pkw::set_Achsen(int ac)
{
	this->achsen = ac;
}

int pkw::get_Achsen()
{
	return this->achsen;
}

#endif
