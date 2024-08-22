#include <iostream>
#include <ctype.h>

//define the class and what needs to be in every instance
class Sample {

	public: 

		int foo;

		Sample(void);
		~Sample(void);

		void bar(void);
};

//define the constructor and destructor and other functions if defined in the class
Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called as well" << std::endl;
	return;
}

void Sample::bar(void)
{
	std::cout << "Member function has been called!" << std::endl;
	return;
}

//define the main file and call an instance of the class and use the members of the class
int	main(void)
{
	Sample new_instance;

	new_instance.foo = 19;

	std::cout << "The value from the member attribute is: " << new_instance.foo << std::endl;

	new_instance.bar();

	return 0;
}
