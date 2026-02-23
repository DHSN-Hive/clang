#include<iostream>

using namespace std;

#ifndef CRAT
#define CRAT

class crat
{
	private:
		int zaehler = 0;
		int nenner = 1;
		int ggT(int a, int b)
		{
			if (b == 0) return a;
			else return ggT(b, a % b);
		}
		void Kuerze()
		{
			int a = this->zaehler, b = this->nenner;
			if (a < 0) a = -a;
			if (b < 0) b = -b;

			int teiler = ggT(a, b);
			if (teiler > 0)
			{
				this->zaehler /= teiler;
				this->nenner /= teiler;
			}
		}
		void SetValues(int z, int n)
		{
			this->zaehler = z;
			this->nenner = n;
			Kuerze();
			
			if (this->nenner < 0)
			{
				this->zaehler = -this->zaehler;	
				this->nenner = -this->nenner;	
			}
		}
	public:
		crat()
		{
			this->SetValues(0, 1);
			cout << "crat(" << *this << ")" << endl;
		}
		
		crat(int z, int n = 1)
		{
			cout << "crat(" << z << ", " << n << ")" << endl;
			this->SetValues(z, n);
		}

		crat(double d)
		{
			int p = 1;
			for (;; p *= 10)
			{
				if (((int) (d * p) - (d * p)) == 0) break;
			}
			
			this->SetValues(p * d, p);
			cout << "crat(" << *this << ")" << endl;
		}

		crat(const crat &r)
		{
			this->SetValues(r.zaehler, r.nenner);
			cout << "crat(" << *this << ")" << endl;
		}
	
		~crat()
		{
			cout << "~crat(" << *this << ")" << endl;
		}

		friend ostream & operator << (ostream &o, const crat &r)
		{
			return o << r.zaehler << "/" << r.nenner;
		}

		crat & operator = (const crat &r)
		{
			cout << "= " << r << endl;
			this->zaehler = r.zaehler;
			this->nenner = r.nenner;

			this->Kuerze();
			return *this;			
		} 
		crat operator * (const crat &r)
		{
			cout << "*" << "(" << r << ")" << endl;
			int z = this->zaehler * r.zaehler;
			int n = this->nenner * r.nenner;
			return crat(z, n);
		}
		crat operator / (const crat &r)
		{
			cout << "/" << "(" << r << ")" << endl;
			int z = this->zaehler * r.nenner;
			int n = this->nenner * r.zaehler;
			return crat(z, n);
		}
		crat operator + (const crat &r)
		{
			int nenner = this->nenner * r.nenner;
			int mulZ1 = this->zaehler * r.nenner;
			int mulZ2 = r.zaehler * this->nenner;
			return crat(mulZ1 + mulZ2, nenner);	
		}
		crat operator - (const crat &r)
		{
			crat temp(-r.zaehler, r.nenner);
			return *this + temp;
		}
		bool operator == (const crat &r)
		{
			// funktioniert, weil crat immer gekuerzt
			return (this->zaehler == r.zaehler) && (this->nenner == r.nenner)	
		}
		bool operator != (const crat &r)
		{
			return !(*this == r);
		}
		bool operator < (const crat &r)
		{
			int z1 = this->zaehler, n1 = this->nenner;
			int z2 = r.zaehler, n2 = r.nenner;
			return z1 * n2 < n1 * z2;	
		}
		bool operator > (const crat &r)
		{
			int z1 = this->zaehler, n1 = this->nenner;
			int z2 = r.zaehler, n2 = r.nenner;
			return z1 * n2 > n1 * z2;	
		}
		bool operator <= (const crat &r)
		{
			return (*this < r) || (*this == r);
		}
		bool operator >= (const crat &r)
		{
			return (*this > r) || (*this == r);
		}
		crat & operator *= (const crat &r)
		{
			return *this = *this * r;	
		}
		crat & operator /= (const crat &r)
		{
			return *this = *this / r;	
		}
		crat & operator += (const crat &r)
		{
			return *this = *this + r;	
		}
		crat & operator -= (const crat &r)
		{
			return *this = *this - r;	
		}
		crat & operator ++ (int x)
		{
			return *this = *this + 1;
		}
		crat & operator -- (int x)
		{
			return *this = *this - 1;
		}
};

#endif

int main()
{
	crat r1(27, 36);
	crat r2(1, 2);
	crat r3(3);
	crat r4;
	crat r5(3.445875);	
	
	r4 = r2 * r3 * 4 / r1;
	r4 *= 2;

	r2--;

	crat r6(3, 4);
	crat r7(6, 8);
	cout << "==" << (r6 <= r7) << endl;
	cout << "+" << (r2 + r3) << endl;
	cout << "-" << (r2 - r2) << endl;

	cout << r1 << ", " << r2 << ", " << r3 << ", " << r4 << ", " << r5 << endl;	

	return 0;
}

