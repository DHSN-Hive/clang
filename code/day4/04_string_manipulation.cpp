#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	double d = 23.6372738;

	cout << "d mit standardpräzision: " << d << endl;
	cout << "d mit setprecision(4): " << setprecision(4) << d << endl;

	return 0;
}
