#include "element.hpp"

#ifndef STUDENT_CPP
#define STUDENT_CPP

void element::init()
{
	this->prev = NULL;
	this->next = NULL;
}

element::element(const student &s)
{
	this->init();
	data = s;
}

element::element(const element &e)
{
	this->init();
	this->data = e.data;
}

bool element::operator< (const element &e)
{
	return this->data < e.data;
}

ostream & operator << (ostream &o, const element &e)
{
	return o << e.data;
}

#endif
