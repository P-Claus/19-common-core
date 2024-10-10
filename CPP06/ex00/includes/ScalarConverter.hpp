#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <iomanip>
#include <sstream>

class ScalarConverter
{
	private:
		//constructor
		ScalarConverter();
		//destructor
	 	~ScalarConverter();
		//copy constructor
		ScalarConverter(const ScalarConverter& other);
		//assignment overload	
		ScalarConverter operator=(const ScalarConverter& rhs);
	public:
		static void	convert(std::string& string);
};

#endif
