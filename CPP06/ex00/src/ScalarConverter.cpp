#include "../includes/ScalarConverter.hpp"
#include <cctype>
#include <exception>
#include <stdexcept>
#include <sstream>

/*	CONSTRUCTORS	*/

/*	DESTRUCTORS	*/


/*	HELPER FUNCTIONS	*/
bool	isChar(std::string& string)
{
	if (string.length() == 1 && (string[0] >= 32 && string[0] <= 126))
	{
		return (true);	
	}
	else
	return (false);
}

bool	isInteger(std::string& string)
{
	std::stringstream ss;

	int integer;

	ss << string;

	ss >> integer;
	if (ss.fail() || !ss.eof())
		return (false);
	else
		return (true);
}

bool	isFloat(std::string& string)
{
	std::string			cleanString;
    std::stringstream 	ss;
    float 				f;

	if (string[string.size() - 1] == 'f')
	{
		cleanString = string.substr(0, string.size()-1);
		ss << cleanString;

		ss >> f;
		if (ss.fail() || !ss.eof())
			return (false);
		else
			return (true);
	}
	return (false);
}

bool	isDouble(std::string& string)
{
    std::stringstream 	ss;
    double 				f;

	ss << string;

	ss >> f;
	if (ss.fail() || !ss.eof())
		return (false);
	else
		return (true);
}




/*	CONVERT	*/
void	ScalarConverter::convert(std::string& string)
{
	std::cout << "string: " << string << std::endl;
	
	if (isInteger(string) == true)
		std::cout << "We have an integer" << std::endl;	
	else if (isChar(string) == true)
		std::cout << "We have a char" << std::endl;
	else if (isFloat(string) == true)
		std::cout << "We have a float" << std::endl;
	else if (isDouble(string) == true)
		std::cout << "We have a double" << std::endl;

		

}
