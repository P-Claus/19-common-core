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

void	display_contacts(PhoneBook *phonebook)
{
	int index  = 0;
	while (index < 8)
	{
		if (phonebook->contact[index].index != 0)
			phonebook->contact[index].print_contacts();
		index++;
	}

}

void	display_contact_header()
{
	std::cout << std::endl;
	std::cout << std::setw(10) << "Index" << "|" <<
	std::setw(10) << "First name" << "|" << std::setw(10) <<
	"Last name" << "|" << std::setw(10) << "Nick name" << std::endl;
}

int	evaluate_answer(PhoneBook *phonebook, std::string answer, int *index, int *counter)
{
	int	search_answer;

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
		add_contact(&phonebook->contact[(*index)++], counter++);
	if (answer == "SEARCH")
	{
		display_contact_header();
		display_contacts(phonebook);
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Enter the index of the contact you want to see: ";
		std::cin >> search_answer;
		std::cout << std::endl;
		if (!phonebook->contact[search_answer - 1].index)
			std::cout << "There is no such index" << std::endl;
		else
			//std::cout << "We have a contact stored at that index!" << std::endl;
			phonebook->contact[search_answer - 1].print_single_contact();
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
