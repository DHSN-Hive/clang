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
		friend ostream & operator << (ostream &, const element &);
};

#endif
