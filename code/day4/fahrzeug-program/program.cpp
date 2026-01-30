#include<iostream>
#include "pkw.hpp"

// Unnötig, aber möglich
#include "fahrzeug.hpp"

using namespace std;

int main()
{
	// statisch
	fahrzeug f1(50, 10);
	pkw p1(100, 5, 2);

	cout << "f1 speed: " << f1.get_Geschwindigkeit() << ", Age: " << f1.get_Alter() << endl; 
	cout << "p1 speed: " << p1.get_Geschwindigkeit() << ", Age: " << p1.get_Alter();
       	cout << ", Achsen: " << p1.get_Achsen() << endl;	

	// dynamisch
	fahrzeug *f2 = new fahrzeug(43, 4);
	pkw *p2 = new pkw(116, 3, 2);

	cout << "f2 speed: " << f2->get_Geschwindigkeit() << ", Age: " << f2->get_Alter() << endl; 
	cout << "p2 speed: " << p2->get_Geschwindigkeit() << ", Age: " << p2->get_Alter();
       	cout << ", Achsen: " << p2->get_Achsen() << endl;

	delete f2;
	delete p2;

	return 0;	
}
