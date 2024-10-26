#include "../includes/BitcoinExchange.hpp"

/*	DEFAULT CONSTRUCTOR	*/
DateAndValue::DateAndValue(): _date(""), _value(0) {}

/*	COPY CONSTRUCTOR	*/
DateAndValue::DateAndValue(const DateAndValue& other)
{
	std::cout << "The copy constructor has been called" << std::endl;
	_date = other._date;
	_value = other._value;
}

/*	COPY ASSIGNMENT OVERLOAD	*/
DateAndValue DateAndValue::operator=(const DateAndValue &rhs)
{
	std::cout << "The copy assignment overload has been called" << std::endl;
	if (this != &rhs)
	{
		_date = rhs._date;
		_value = rhs._value;
	}

	return (*this);
}

/*	DESTRUCTOR	*/
DateAndValue::~DateAndValue() {}

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

/*	MISC.	*/
void DateAndValue::printOutput()
{
    std::string		dateString = getDate();
    float 			valueFloat = getValue();

    if (dateAndValueMap.find(dateString) != dateAndValueMap.end())
        std::cout << dateString << " => " << valueFloat << " = " << dateAndValueMap[dateString] * valueFloat << std::endl;
    else
    {
        std::string closestDateString = findClosestDateBefore(dateString);
		std::cout << dateString << " => " << valueFloat << " = " << dateAndValueMap[closestDateString] * valueFloat << std::endl;
    }
}

