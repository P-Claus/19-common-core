#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Base
{
	private:

	public:
		virtual ~Base();
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

Base * 	generate(void);
void	identify(Base* p);
void	identify(Base& p);


#endif
