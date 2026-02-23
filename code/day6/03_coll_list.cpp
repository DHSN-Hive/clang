#include<iostream>
#include<string>
#include<list>

using namespace std;

class student 
{
    private:
            string name;
            int mtr;
    public:
            student()
            {
                this->name = "";
                this->mtr = 0;
            }
            student(int m, string n)
            {
                this->mtr = m;
                this->name = n;
            }
            student(const student &s)
            {
                this->mtr = s.mtr;
                this->name = s.name;
            }
            friend ostream & operator << (ostream &o, const student &s)
            {
                return o << "M: " << s.mtr << "N: " << s.name;
            }
};

int main()
{
    list<student> l1;

    l1.push_back(123, "Roland");
    l1.push_back(456, "Moritz");
    l1.push_back(789, "Raphael");

    list<student>::iterator it;
    cout << "Ausgabe alte Methode" << endl;

    for(it = l1.begin(); it != l1.end(); it++)
    {
        student s = *it;
        cout << "Test: " << s << endl;
    }

    cout << "Ausgabe neue Methode" << endl;

    for(auto it2 : l1)
    {
        student s = it2;
        cout << "Test: " << s << endl;
    }
}
