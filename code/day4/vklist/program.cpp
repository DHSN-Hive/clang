#include<iostream>
#include "element.hpp"

int main()
{
	element e(student(1234, "Mustermann", "Max"));
	element e2({777, "Musterfrau", "Ingrid"});

	cout << "test: " << e << endl;
	cout << "test 2: " << e2 << endl;

	return 0;
}
