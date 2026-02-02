#include<iostream>

#ifndef STUDENT_HPP
#define STUDENT_HPP

using namespace std;

class student
{
	private:
		void init();

	public:
		char *vorname;
		char *nachname;
		int mtr;
	
		student();
		student(int, const char *, const char *);
		~student();
		student & operator=(const student &);
		bool operator < (const student &);
		void set_Vorname(const char *);
		void set_Nachname(const char *);
		void set_Mtr(int);
		friend ostream & operator << (ostream &, const student &);
};

#endif
