#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

class DateAndValue
{
	private:
	public:
		std::string		_date;
		float			_value;
		//constructor
		DateAndValue();

		//parameter cosntructor
		DateAndValue(std::string date);

		//copy constructor
		DateAndValue(const DateAndValue& other);

		//copy assignment overload
		DateAndValue operator=(const DateAndValue& rhs);

		//destructor
		~DateAndValue();

		//getters
		std::string& getDate(void);
		float& getValue(void);
	
		//setters
		void setDate(std::string date);
		void setValue(float value);

		//misc.
		void printOutput(void);
};

extern std::map<std::string, float> dateAndValueMap;

void	exit_handler(std::string& error_message);

#endif
