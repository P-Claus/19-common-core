#include "../includes/main.hpp"

Base::~Base()
{
}

Base * generate(void)
{
	srand(time(0));

	int	randomNb = (rand() % 3) + 1;

	Base *baseObj = NULL;

	switch (randomNb) 
	{
		case 1:
			baseObj = new A();
			break;
		case 2:
			baseObj = new B();
			break;
		case 3:
			baseObj = new C();
			break;
	}

	return (baseObj);
}

void	identify(Base* p)
{
	A *aPtr = dynamic_cast<A*>(p);
	if (aPtr)
		std::cout << "The type of the pointer is A" << std::endl;
	B *bPtr = dynamic_cast<B*>(p);
	if (bPtr)
		std::cout << "The type of the pointer is B" << std::endl;
	C *cPtr = dynamic_cast<C*>(p);
	if (cPtr)
		std::cout << "The type of the pointer is C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& aRef = dynamic_cast<A&>(p);
		std::cout << "The type of the reference is A" << std::endl;
		(void)aRef;
		return ;
	}
	catch (std::bad_cast& e)
	{
	}
	try
	{
		B& bRef = dynamic_cast<B&>(p);
		std::cout << "The type of the reference is B" << std::endl;
		(void)bRef;
		return ;
	}
	catch (std::bad_cast& e)
	{
	}
	try
	{
		C& cRef = dynamic_cast<C&>(p);
		std::cout << "The type of the reference is C" << std::endl;
		(void)cRef;
		return ;
	}
	catch (std::bad_cast& e)
	{
	}
}

int	main(void)
{
	Base *basePtr = generate();
	Base& baseRef = *basePtr;

	identify(basePtr);
	identify(baseRef);

	delete basePtr;
}