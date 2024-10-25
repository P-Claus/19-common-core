#include "../includes/BitcoinExchange.hpp"

/*	DEFAULT CONSTRUCTOR	*/
DateAndValue::DateAndValue()
{
	//std::cout << "The default constructor has been called" << std::endl;
}

/*	DESTRUCTOR	*/
DateAndValue::~DateAndValue()
{
	//std::cout << "The destructor has been called" << std::endl;
}

/*	GETTERS	*/
std::string& DateAndValue::getDate()
{
	return (_date);
}

float& DateAndValue::getValue()
{
	return (_value);
}
