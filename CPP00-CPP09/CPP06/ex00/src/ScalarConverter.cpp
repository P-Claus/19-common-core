#include "../includes/ScalarConverter.hpp"

/*	HELPER FUNCTIONS	*/
bool	isChar(std::string& string)
{
	if (string.length() == 1 && (string[0] >= 32 && string[0] <= 126))
		return (true);	
	else
		return (false);
}

bool	isInteger(std::string& string)
{
	std::stringstream 	ss;
	long long 				nb;

	ss << string;
	ss >> nb;

	if (ss.fail() || !ss.eof())
		return (false);
	if (nb > INT_MAX || nb < INT_MIN)
		return (false);
	else
		return (true);
}

bool	isFloat(std::string& string)
{
	if (string == "nanf" || string == "+inff" || string == "-inff")
		return (true);
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
	if (string == "nan" || string == "+inf" || string == "-inf")
		return (true);
    std::stringstream 	ss;
    double 				f;

	ss << string;
	ss >> f;

	if (ss.fail() || !ss.eof())
		return (false);
	else
		return (true);
}

void	convertInt(std::string& string, std::stringstream& ss)
{
	int	integer; 

	ss << string;
	ss >> integer;

	if (integer < 32 || integer > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(integer) << std::endl;
	std::cout << "int: " << integer << std::endl;
	std::cout << std::fixed << std::setprecision(1);

	std::cout << "float: " << static_cast<float>(integer) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(integer) << std::endl;
}

void	convertDouble(std::string& string, std::stringstream& ss)
{
	double	db;
	
	ss << string;
	ss >> db;
	
	if (string == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (string == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (string == "+inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else
	{
		if (db < 32 || db > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(db) << std::endl;
		if (db > INT_MAX || db < INT_MIN)
			std::cout << "int: Non displayable" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(db) << std::endl;	
		std::cout << std::fixed << std::setprecision(2);
		std::cout << "float: " << static_cast<float>(db) << "f" << std::endl;
		std::cout << "double: " << (db) << std::endl;
	}
}

void	convertFloat(std::string& string, std::stringstream& ss)
{
	std::string		cleanString;
	float			flt;

	cleanString = string.substr(0, string.size()-1);
	
	ss << cleanString;
	ss >> flt;
	
	if (string == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (string == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (string == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else
	{
		if (flt < 32 || flt > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(flt) << std::endl;

		if (flt > INT_MAX || flt < INT_MIN)
			std::cout << "int: Non displayable" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(flt) << std::endl;	
		
		std::cout << std::fixed << std::setprecision(2);
		std::cout << "float: " << flt << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(flt) << std::endl;
	}
}

void	convertChar(std::string& string)
{
	char		character;
	
	character = string[0];
	
	std::cout << "char: " << character << std::endl;
	std::cout << "int: " << static_cast<int>(character) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(character) << "f"<< std::endl;
	std::cout << "double: " << static_cast<double>(character) << std::endl;
}

/*	CONVERT	*/
void	ScalarConverter::convert(std::string& string)
{
	std::stringstream		ss;
	if (isInteger(string) == true)
		convertInt(string, ss);
	else if (isChar(string) == true)
		convertChar(string);
	else if (isFloat(string) == true)
		convertFloat(string, ss);
	else if (isDouble(string) == true)
		convertDouble(string, ss);
	else
		std::cout << "Impossible to do a conversion" << std::endl;
}
