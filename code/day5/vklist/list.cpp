#include "list.hpp"

#ifndef LIST_CPP
#define LIST_CPP

using namespace std;

list::list()
{
	this->Init();
}

list::~list()
{
	if (this->firstElement == NULL) return;

	/* cleanup */

	element *tempElement = this->firstElement;
	while (this->firstElement != NULL)
	{
		this->firstElement = tempElement->next;
		delete tempElement;
		tempElement = this->firstElement;
	}

	this->lastElement = NULL;
}

list::list(const list &l)
{
	this->Init();
	element *oldListElement = l.firstElement;

	while(oldListElement != NULL)
	{
		AddElement(oldListElement);
		oldListElement = oldListElement->next;
	}
}

void list::Init()
{
	this->firstElement = this->lastElement = NULL;
}

void list::AddElement(element *e)
{
	if (this->firstElement == NULL)
	{
		this->firstElement = e;
	}
	else
	{
		this->lastElement->next = e;
		e->prev = this->lastElement;
	}

	this->lastElement = e;
}

void list::InsElement(element *e)
{
	if (this->firstElement == NULL) return this->AddElement(e);

	this->firstElement->prev = e;
	e->next = this->firstElement;
	this->firstElement = e;
}

void list::List()
{
	element *tempElement = this->firstElement;
	while(tempElement != NULL)
	{
		cout << *tempElement << endl;
		tempElement = tempElement->next;
	}
}

void list::RList()
{
	element *tempElement = this->lastElement;
	while(tempElement != NULL)
	{
		cout << *tempElement << endl;
		tempElement = tempElement->prev;
	}
}

#endif
