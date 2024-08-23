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

void	add_contact(PhoneBook *phonebook)
{
	(void)phonebook;
	std::cout << "The contact wants to be added" << std::endl;
}

int	evaluate_answer(PhoneBook *phonebook, std::string answer)
{
	if (answer == "EXIT")
	{
		std::cout << "Ending the program and destroying all contacts forever..." << std::endl;
		return (1);
	}
	if (answer == "ADD")
	{
		add_contact(phonebook);
	}
	return (0);
}

int	main(void)
{
	PhoneBook phonebook;
	std::string answer;

	print_phonebook_header();
	while (1)
	{
		display_prompt(&answer);
		if (evaluate_answer(&phonebook, answer) == 1)
			break;
	}



	return (0);
}
