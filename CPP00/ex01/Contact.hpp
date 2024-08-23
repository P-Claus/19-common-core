#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iomanip>
# include <iostream>
# include <sstream>
# include <string>

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

	void print_contact()
	{
		std::cout << std::setw(10) << index << "|" <<
		std::setw(10) << firstName << "|" << std::setw(10) <<
		lastName << "|" << std::setw(10) << nickName << std::endl;
	}

	Contact(void);
	~Contact(void);
};

//contact constructor
Contact::Contact(void)
{
	std::cout << "The constructor in the contact has been called" << std::endl;
	return ;
}

//contact destructor
Contact::~Contact(void)
{
	std::cout << "The destructor in the contact has been called" << std::endl;
	return ;
}

#endif
