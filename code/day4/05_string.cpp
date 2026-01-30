#include<iostream>

using namespace std;

class mystring
{
	private:
		char *data = NULL;
	public:
		mystring()
		{
			this->data = NULL;
		}
		mystring(char *s)
		{
			this->set_Data(s);
		}
		~mystring()
		{
			this->delete_Data();
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
};

int main()
{
	mystring s1("Mustermann");
	mystring s2("Test");

	cout << "s1 ist: "; s1.output(); cout << endl;
	cout << "s1 ist: "; s1.output(); cout << endl;
	
	s2 = s1;
		
	return 0;
}
