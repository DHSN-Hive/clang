#include<iostream>
#include "list.hpp"

int main()
{
	// element e(student(1234, "Mustermann", "Max"));
	// element e2({777, "Musterfrau", "Ingrid"});
	
	list l1;

	l1.AddElement(new element(student(1234, "Mustermann", "Hans")));
	l1.AddElement(new element({1212, "Musterfrau", "Brigitte"}));
	l1.InsElement(new element({9999, "Mayer", "Kerstin"}));
	l1.AddElement(new element({4747, "Mueller", "Thomas"}));
	
	list l2(l1);

	l2.AddElement(new element({22, "Zeppelin", "Hans"}));
	l1.InsElement(new element({007, "Bond", "James"}));

	cout << "list l1" << endl;
	l1.List();
	cout << "reverse list l1" << endl;
	l1.RList();

	cout << "list l2" << endl;
	l2.List();

	l2.Sort();

	cout << "sorted l2" << endl;
	l2.List();

	return 0;
}
