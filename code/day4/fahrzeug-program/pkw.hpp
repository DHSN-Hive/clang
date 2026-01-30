#include<iostream>
#include "fahrzeug.hpp"

#ifndef PKW_HPP
#define PKW_HPP

class pkw: public fahrzeug
{
	private:
		int achsen = 0;
	public:
		pkw();
		pkw(int, int, int);
		~pkw();
		void set_Achsen(int);
		int get_Achsen();

	protected:
};

#endif
