#include "../includes/BitcoinExchange.hpp"

/*	DEFAULT CONSTRUCTOR	*/
DateAndValue::DateAndValue(): _date(""), _value(0)
{
	//std::cout << "The default constructor has been called" << std::endl;
}

/*	COPY CONSTRUCTOR	*/
/*
DateAndValue::DateAndValue(const DateAndValue& other)
{

}
*/
/*	COPY ASSIGNMENT OVERLOAD	*/
/*
DateAndValue DateAndValue::operator=(const DateAndValue &rhs)
{

	return (*this);
}
*/
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

/*	SETTERS	*/
void	DateAndValue::setDate(std::string& date)
{
	_date = date;
}

void	DateAndValue::setValue(float value)
{
	_value = value;
}
