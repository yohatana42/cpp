#ifndef CASTBASE_HPP
 #define CASTBASE_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <exception>

class castBase
{
	public:
		castBase();
		castBase(const castBase& src);
		castBase& operator=(const castBase& src);
		~castBase();
		Base * generate(void);
		void identify(Base* p);
		void identify(Base& p);
	private:
};

#endif
