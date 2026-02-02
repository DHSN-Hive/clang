#include "student.hpp"
#include<string.h>

#ifndef STUDENT_CPP
#define STUDENT_CPP

void student::init()
{
	this->mtr = 0;
	this->vorname = NULL;
	this->nachname = NULL;
}

student::student()
{
	this->init();
}

student::student(int mtr, const char *n, const char *v)
{
	this->init();
	this->set_Mtr(mtr);
	this->set_Nachname(n);
	this->set_Vorname(v);
}

student::~student()
{
	this->mtr = 0;

	if(this->vorname != NULL) delete [] this->vorname;
	if(this->nachname != NULL) delete [] this->nachname;
	this->vorname = NULL;
	this->nachname = NULL;
}

student & student::operator=(const student & s)
{
	this->init();
	this->set_Mtr(s.mtr);
	this->set_Nachname(s.nachname);
	this->set_Vorname(s.vorname);

	return *this;
}

bool student::operator<(const student &s)
{
	return this->mtr < s.mtr;
}

void student::set_Vorname(const char *s)
{
	if(s == NULL) return;

	if(this->vorname != NULL) delete [] this->vorname;

	this->vorname = new char[strlen(s) + 1];
	strcpy(this->vorname, s);
}

void student::set_Nachname(const char *s)
{
	if(s == NULL) return;

	if(this->nachname != NULL) delete [] this->nachname;

	this->nachname = new char[strlen(s) +1];
	strcpy(this->nachname, s);
}

void student::set_Mtr(int mtr)
{
	this->mtr = mtr;
}

ostream & operator << (ostream &o, const student &s)
{
	return o << "S: " << s.mtr << ", " << s.nachname << ", " << s.vorname;
}
#endif
