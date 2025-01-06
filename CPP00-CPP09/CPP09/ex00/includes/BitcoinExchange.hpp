#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>
#include <cstddef>

class DateAndValue
{
	private:
		std::string		_date;
		float			_value;
	public:
		//constructor
		DateAndValue();

		//parameter constructor 
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
		void setDate(std::string& date);
		void setValue(float value);

		//misc.
		void printOutput(void);
};

extern std::map<std::string, float> dateAndValueMap;

std::string 	findClosestDateBefore(const std::string& targetDate);
void			exit_handler(std::string& error_message);

#endif
