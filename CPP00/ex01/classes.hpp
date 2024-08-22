#ifndef CLASSES_H
#define CLASSES_H


#include <iostream>
#include <string>
#include <iomanip>

class Contact {

public:
	int index;
	std::string firstName;
	std::string	lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string secret;

	void fill_contact(int i, std::string fName, std::string lName, std::string nName, std::string pNumber, std::string sec)
	{
		index = i;
		firstName = fName;
		lastName = lName;
		nickName = nName;
		phoneNumber = pNumber;
		secret = sec;

		//std::cout << firstName << lastName << std::endl;
	}

	void	print_contact()
	{
		std::cout << std::setw(10) << index << "|" << std::setw(10) << firstName << "|" << std::setw(10) << lastName << "|" << std::setw(10) << nickName << std::endl;
	}

	Contact(void);
	~Contact(void);

};

class PhoneBook {

public:

	Contact contact[7];

	void	print_contact_header()
	{
		std::cout << std::setw(10) << "INDEX" << "|" << std::setw(10) << "FIRSTNAME" << "|" << std::setw(10) << "LASTNAME" << "|" << std::setw(10) << "NICKNAME" << std::endl;
	}
	PhoneBook(void);
	~PhoneBook(void);

};

#endif
