#include "classes.hpp"


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



//contact constructor
Contact::Contact(void)
{
	std::cout << "The constructor in the contact has been called" << std::endl;
	return;
}



//contact destructor
Contact::~Contact(void)
{
	std::cout << "The destructor in the contact has been called" << std::endl;
	return;
}

bool	array_contains_value(Contact aray[], int size, int value)
{
	int iter = 0;

	while (iter <= size)
	{
		if (array[iter++] == value)
			return (true);
	}
	return (false);
}



int	main(void)
{
	PhoneBook phonebook;

	std::string answer;
	std::string	firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string secret;

	int	counter = 1;
	int index = 0;
	int print_counter = 0;
	int	print_index = 0;
	int	search_index;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "===================================================" << std::endl;
	std::cout << "===================| PHONEBOOK |===================" << std::endl;
	std::cout << "===================================================" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Please enter one of the following  commands:" << std::endl;
	std::cout << std::endl;
	std::cout << "	ADD (to save a new contact)" << std::endl;
	std::cout << "	SEARCH (to dipsplay a specific contact)" << std::endl;
	std::cout << "	EXIT (to exit the program)" << std::endl;
	while (1)
	{
		std::cout << std::endl;
		std::cout << "Enter the command (ADD, SEARCH, EXIT): ";
		std::cin >> answer;
		std::cout << answer << std::endl;

		if (answer == "EXIT")
		{
			std::cout << "Ending the pogram and destroying all contacts forever..." << std::endl;
			break ;
		}
		
		else if (answer == "ADD")
		{
			if (index == 7)
			{
				index = 0;
				counter = 1;
			}
			std::cout << "Enter the first name: ";
			std::cin >> firstName;
			std::cout << "Enter the last name: ";
			std::cin >> lastName;
			std::cout << "Enter the nickname: ";
			std::cin >> nickName;
			std::cout << "Enter the phone number: ";
			std::cin >> phoneNumber;
			std::cout << "Enter thier darkest secret...: ";
			std::cin >> secret;
			phonebook.contact[index++].fill_contact(counter, firstName, lastName, nickName, phoneNumber, secret);
			counter++;
			if (print_counter != 7)
				print_counter++;
		}
		else if (answer == "SEARCH")
		{
			while (1)
			{

			phonebook.print_contact_header();
			while (print_index < print_counter)
				phonebook.contact[print_index++].print_contact();
			print_index = 0;
			std::cout << std::endl;
			std::cout << "Enter the index of the contact you want to see: ";
			std::cin >> search_index;
			std::cout << search_index << std::endl;
			if (!array_contains_value(phonebook.contact, 7, search_index))
				std::cout << "Please choose an index that exists...";
			}
				

		}
		else if (answer != "EXIT" || answer != "ADD" || answer != "SEARCH")
			std::cout << "Please choose ADD, SEARCH or EXIT" << std::endl;

	}


	return 0;
}
