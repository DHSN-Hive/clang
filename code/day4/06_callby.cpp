#include<iostream>

using namespace std;

// CallByValue
int plusbyvalue(int a, int b)
{
	int c = a + b;

	a = 55;
	b = 66;

	return c;
}

int plusbypointer(const int *a, const int *b)
{
	int c = (*a) + (*b);

	 /* Fehler wegen const prefix
	*a = 55;
	*b = 66;
	*/

	return c;
}

int plusbyreference(const int &a, const int &b)
{
	int c = a + b;

	/* Fehler wegen const prefix
	a = 55;
	b = 66;
	*/

	return c;
}

int main()
{
	int a1 = 4, a2 = 5, a3 = 0;

	cout << "a1: " << a1 << ", a2: " << a2 << ", a3: " << a3 << endl;

	// CallByValue - kein Risiko für Eingabevariablen (Parameter)
	a3 = plusbyvalue(a1, a2);
	cout << "a1: " << a1 << ", a2: " << a2 << ", a3: " << a3 << endl;

	int b1 = 4, b2 = 5, b3 = 0;

	cout << "b1: " << b1 << ", b2: " << b2 << ", b3: " << b3 << endl;

	// CallByPointer - Risiko für Eingabevariablen (Parameter) ist vorhanden
	b3 = plusbypointer(&b1, &b2);
	cout << "b1: " << b1 << ", b2: " << b2 << ", b3: " << b3 << endl;

	int c1 = 4, c2 = 5, c3 = 0;
	cout << "c1: " << a1 << ", c2: " << c2 << ", c3: " << c3 << endl;

	// CallByReference - Risiko für Eingabevariablen (Parameter) ist vorhanden
	c3 = plusbyreference(c1, c2);
	cout << "c1: " << c1 << ", c2: " << c2 << ", c3: " << c3 << endl;
}
