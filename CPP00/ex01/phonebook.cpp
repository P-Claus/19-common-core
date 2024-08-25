#include <stdio.h>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void	print_phonebook_header(void)
{
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
	std::cout << "	SEARCH (to display a specific contact)" << std::endl;
	std::cout << "	EXIT (to exit the program)" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

void	display_prompt(std::string *answer)
{
	std::cout << std::endl;
	std::cout << "Enter the command (ADD, SEARCH, EXIT): ";
	std::cin >> *answer;
	std::cout << *answer << std::endl;
}

void	add_contact(Contact *contact, int *counter)
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string secret;

	std::cout << "Enter the first name: ";
	std::cin >> firstName;
	std::cout << "Enter the last name: ";
	std::cin >> lastName;
	std::cout << "Enter the nickname: ";
	std::cin >> nickName;
	std::cout << "Enter the phone number: ";
	std::cin >> phoneNumber;
	std::cout << "Enter their darkest secret...: ";
	std::cin >> secret;

	contact->fill_contact((*counter)++, firstName, lastName, nickName, phoneNumber, secret);
}

int	evaluate_answer(PhoneBook *phonebook, std::string answer, int *index, int *counter)
{
	if (*index == 8)
	{
		*index = 0;
		*counter = 1;
	}
	if (answer == "EXIT")
	{
		std::cout << "Ending the program and destroying all contacts forever..." << std::endl;
		return (1);
	}
	if (answer == "ADD")
	{
		add_contact(&phonebook->contact[(*index)++], counter++);
		phonebook->contact[0].print_contact();
		phonebook->contact[1].print_contact();
		phonebook->contact[2].print_contact();
		phonebook->contact[3].print_contact();
		phonebook->contact[4].print_contact();
		phonebook->contact[5].print_contact();
		phonebook->contact[6].print_contact();
		phonebook->contact[7].print_contact();
	}
	return (0);
}

int	main(void)
{
	PhoneBook phonebook;
	std::string answer;
	int	counter = 1;
	int	index = 0;

	print_phonebook_header();
	while (1)
	{
		display_prompt(&answer);
		if (evaluate_answer(&phonebook, answer, &index, &counter) == 1)
			break;
	}



	return (0);
}
