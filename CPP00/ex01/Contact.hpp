#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iomanip>
# include <iostream>
# include <sstream>
# include <string>
# include <cstring>

class Contact
{
  public:
	int index;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string secret;

	void fill_contact(int i, std::string fName, std::string lName,
			std::string nName, std::string pNumber, std::string sec)
	{
		index = i;
		firstName = fName;
		lastName = lName;
		nickName = nName;
		phoneNumber = pNumber;
		secret = sec;

		//std::cout << firstName << lastName << std::endl;
	}

	void	truncate_string(std::string *string)
	{
		if ((*string).length() > 10)
		{
			(*string).resize (9);
			*string = *string + ".";
		}
	}

	void print_contacts()
	{
		truncate_string(&firstName);
		truncate_string(&lastName);
		truncate_string(&nickName);
		truncate_string(&phoneNumber);
		truncate_string(&secret);

		std::cout << std::setw(10) << index << "|" <<
		std::setw(10) << firstName << "|" << std::setw(10) <<
		lastName << "|" << std::setw(10) << nickName << std::endl;
	}

void	print_single_contact()
	{
		std::cout << "Firstname: " << firstName << std::endl;
		std::cout << "Last name: " << lastName << std::endl;
		std::cout << "Nickname: " << nickName << std::endl;
		std::cout << "Phone number: " << phoneNumber << std::endl;
		std::cout << "Their darkest secret: " << secret << std::endl;
	}

	Contact(void);
	~Contact(void);
};

//contact constructor
Contact::Contact(void)
{
	std::cout << "The constructor in the contact has been called" << std::endl;
	index = 0;
	firstName = "";
	lastName = "";
	nickName = "";
	phoneNumber = "";
	secret = "";
	return ;
}

//contact destructor
Contact::~Contact(void)
{
	std::cout << "The destructor in the contact has been called" << std::endl;
	return ;
}

#endif
