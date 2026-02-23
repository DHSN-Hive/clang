#include<iostream>

template<class T>

class container
{
	public:
		T * element;
		container *next;
		container() { this->element = NULL; this->next = NULL; }
		container(T * e) { this->element = e; this->next = NULL; } 
}

class mystack
{
	private:
		container<T> *firstElement;
	public:
		mystack() { this->firstElement = NULL; }
		~mystack { this->CleanUp(); }
		void Add(T e)
		{
			container<T> *newElement = new container<T>(e);
			newElement->next = this->firstElement;
			this->firstElement = newElement;
		}
		void Del()
		{
			if (this->firstElement == NULL) return;

			container<T> *tempElement = this->firstElement->next;
			delete this->firstElement; 
			this->firstElement = tempElement;

		}
		void Print()
		{

		}
		void CleanUp()
		{

		}
			
};

int main()
{
	
	return 0;
}

