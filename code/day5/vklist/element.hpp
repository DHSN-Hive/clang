#include "student.hpp"
#include <iostream>

#ifndef ELEMENT_HPP
#define ELEMENT_HPP

class element
{
	private:
		student data;
		void init();
	public:
		element *prev;
		element *next;
		element(const student&);
		element(const element&);
		bool operator < (const element &);
		friend ostream & operator << (ostream &, const element &);
};

#endif
