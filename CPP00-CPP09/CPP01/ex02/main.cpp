#include <string>
#include <iostream>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";

	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "Address of the string: " << &string << std::endl;
	std::cout << "Address of stringPTR: " << &stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << std::endl;

	std::cout << "Address of the string: " << &string << std::endl;
	std::cout << "Address of the string through stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of the string through stringREF: " << &stringREF << std::endl;
	
	std::cout << "Value of the string: " << string << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;
}
