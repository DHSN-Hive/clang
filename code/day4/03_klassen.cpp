#include<iostream>

using namespace std;

class animal
{
	private:
		int age;
	public:
		animal()
		{
			this->age = 0;
		}
		animal(int age)
		{
			this->set_Age(age);
		}
		~animal()
		{
			cout << " -animal()" << endl;
			this->age = 0;
		}
		void set_Age(int age)
		{
			this->age = age;
		}
		int get_Age()
		{
			return this->age;
		}
	protected:
};

int main()
{
	// Static
	animal a;	/* Aufruf statisch mit default Konstruktor */
	animal b(4);	/* Aufruf statisch mit Wertekonstruktor */

	cout << "Age von a ist: " << a.get_Age() << endl;
	cout << "Age von b ist: " << b.get_Age() << endl;

	animal *c = NULL;
	animal *d = NULL;

	c = new animal;
	d = new animal(5);

	cout << "Age von c ist: " << c->get_Age() << endl;
	cout << "Age von d ist: " << d->get_Age() << endl;

	delete c;
	delete d;

	cout << "vor return 0" << endl;
	return 0;
}
