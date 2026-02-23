#include<iostream>
#include<string.h>
#include<list>

using namespace std;

template<class T>
class container
{
	public:
		T element;
		container *next;
		container() 
        {
            this->element = NULL; 
            this->next = NULL; 
        }
		container(T &e) 
        { 
            this->element = e; 
            this->next = NULL; 
        } 
        
};

template<class T>
class mystack
{
	private:
		container<T> *firstElement;
	public:
		mystack() { this->firstElement = NULL; }
		~mystack() { this->CleanUp(); }
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
			container<T> *tempElement = this->firstElement;
			int count = 0;

			while(tempElement != NULL)
			{
				cout << "#" << count << ": " << tempElement->element << endl;
				count++;
				tempElement = tempElement->next;
			}

		}
		void CleanUp()
		{
			while (this->firstElement != NULL) this->Del();
		}
			
};


class student
{
	private:
		char *name;
        int mtr;
	public:
		student() 
        {
            this->mtr = 0;
            this->name = new char[1];
            this->name[0] = '\0';
        }
		student(int m, const char *n)
	    {
            this->mtr = m;
            this->name = new char[strlen(n)+1];
            strcpy(this->name, n);
	    }
        student(const student &s)
        {
            this->mtr = s.mtr;
            this->name = new char[strlen(s.name)+1];
            strcpy(this->name, s.name);
        }
		~student() 
        {
            delete [] this->name; 
        }
		friend ostream & operator << (ostream &o, const student &s)
        {
            return o << s.name;
        }
        student & operator =(const student &s)
        {
            delete [] this->name;
            this->name = new char[strlen(s.name)+1];
            strcpy(this->name, s.name);

            this->mtr = s.mtr;
            return *this;
        }
};

int main()
{
	mystack<int> m1;

	m1.Add(3);
	m1.Add(6);
	m1.Add(7);
	m1.Print();

	m1.Del();
	m1.Print();

	mystack<student> m2;
	
	m2.Add(student(1, "Maurice"));
	m2.Print();
	m2.Del();

	return 0;
}

