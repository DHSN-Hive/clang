#include<iostream>

using namespace std;

class mystring
{
	private:
		char *data = NULL;
	public:
		mystring()
		{
			cout << "default constructor";
			this->data = NULL;
		}
		mystring(char *s)
		{
			cout << "value constructor " << s << endl;
			this->set_Data(s);
		}
		mystring(const mystring &m)
		{
			cout << "copy constructor: " << m.data << endl;
			this->set_Data(m.data);
		}
		~mystring()
		{
			cout << "deconstructor: " << this->data << endl;
			this->delete_Data();
		}
		mystring & operator = (const mystring &m)
		{
			cout << "= operator: " << m.data << endl;
			this->set_Data(m.data);

			return *this;
		}

		void delete_Data()
		{
			if(this->data != NULL) delete [] this->data;
			this->data = NULL;
		}
		int get_Len(char *s)
		{
			int len = 0;
			for(; s[len] != '\0'; len++);
			return len;
		}
		void set_Data(char *s)
		{
			this->delete_Data();

			if (s == NULL) return;

			int newLen = this->get_Len(s);

			this->data = new char[newLen + 1];

			for(int c=0; c < newLen; c++)
			{
				this->data[c] = s[c];
			}

			this->data[newLen] = '\0';
		}
		void output()
		{
			cout << this->data;
		}
		friend ostream & operator << (ostream &o, const  mystring &m)
		{
			o << m.data;
			return o;
		}
};

int main()
{
	mystring s1("Mustermann");
	mystring s2("Test");

	cout << "s1 ist: " << s1 << endl;
	cout << "s2 ist: " << s2 << endl;
	
	s2 = s1;

	cout << "s1 ist: " << s1 << endl;
	cout << "s2 ist: " << s2 << endl;
	
	s1 = "Neuer Test";
		
	return 0;
}
