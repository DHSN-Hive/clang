#include "element.hpp"
#include "student.hpp"
#include<iostream>

#ifndef LIST_HPP
#define LIST_HPP

class list
{
	private:
		element *firstElement;
		element *lastElement;
		// element * NewElement();
		void Init();
	
	public:
		list();			/* default constructor */
		~list();		/* destructor */		
		list(const list &);	/* copy constructor */
		void AddElement(element *);
		void InsElement(element *);
		void List();
		void RList();
		void Sort();
		element * Swap(element *);
};

#endif
