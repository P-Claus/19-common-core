#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class PhoneBook {

public:

	Contact contact[8];

	void	print_contact_header()
	{
		std::cout << std::setw(10) << "INDEX" << "|" <<
		std::setw(10) << "FIRSTNAME" << "|" << std::setw(10) <<
		"LASTNAME" << "|" << std::setw(10) << "NICKNAME" << std::endl;
	}
	PhoneBook(void);
	~PhoneBook(void);

};

//phonebook constructor
PhoneBook::PhoneBook(void)
{
	std::cout << "The constructor in the PhoneBook has been called" << std::endl;
}



//phonebok destructor
PhoneBook::~PhoneBook(void)
{
	std::cout << "The destructor in the PhoneBook has been called" << std::endl;
	return;
}

#endif
