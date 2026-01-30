#include<iostream>

#ifndef FAHRZEUG_HPP
#define FAHRZEUG_HPP

class fahrzeug
{
	private:
		int geschwindigkeit = 0;
	public:
		fahrzeug();
		fahrzeug(int, int);
		~fahrzeug();
		void set_Geschwindigkeit(int);
		int get_Geschwindigkeit();
		void set_Alter(int);
		int get_Alter();
	protected:
		int alter = 0;
};

#endif
