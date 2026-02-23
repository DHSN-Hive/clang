#include<iostream>

using namespace std;

int plusA(int a, int b)
{
	int c = a + b;
	return c;
}

// Klasse crational für Nutzung in Template
class crational
{
	private:
		int zaehler;
		int nenner;
	public:
		crational() { this->zaehler = 0; this->nenner = 1; }
		crational(int z, int n=1) { this->zaehler = z; this->nenner = n; }

		friend ostream & operator << (ostream &o, const crational &r) { return o << "(" << r.zaehler << "/" << r.nenner << ")"; }

		// Mindest notwendige Operator für plusB Beispiel
		
		crational & operator = (const crational &r) { this->zaehler = r.zaehler; this->nenner = r.nenner; return *this; }
		crational operator + (const crational &r) const
		{
			int z = this->zaehler * r.nenner + this->nenner * r.zaehler;
			int n = this->nenner * r.nenner;
			return crational(z, n);
		}
};

template<typename T>
T plusB(T a, T b)
{
	T c = a + b;
	return c;
}

int main()
{
	int i1 = 5, i2 = 6;
	int i3 = plusA(i1, i2);
	cout << "i3 = " << i3 << endl;

	double d1 = 4.3, d2 = 5.5;
	double d3 = plusB(d1, d2);
	cout << "d3 = " << d3 << endl;

	int i4 = plusB(i1, i2);
	cout << "i4 = " << i4 << endl;

	crational cr1(4,2), cr2(9,2);
	crational cr3 = plusB(cr1, cr2);
	cout << "cr3 = " << cr3 << endl;

	return 0;
}
