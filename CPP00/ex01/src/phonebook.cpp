#include "../includes/main.hpp"

void	PhoneBook::print_contact_header(void)
{
		std::cout << std::setw(10) << "INDEX" << "|" <<
		std::setw(10) << "FIRSTNAME" << "|" << std::setw(10) <<
		"LASTNAME" << "|" << std::setw(10) << "NICKNAME" << std::endl;
}

void	PhoneBook::print_header(void)
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

void	PhoneBook::display_prompt(std::string *answer)
{
	std::cout << std::endl;
	std::cout << "Enter the command (ADD, SEARCH, EXIT): ";
	std::cin >> *answer;
	std::cout << *answer << std::endl;
}

void	PhoneBook::add_contact(Contact *contact, int *counter)
{
	std::string	input_data[5];
	int	new_index = (*counter)++;

	std::cin.ignore();
	std::cout << "Enter the first name: ";
	getline(std::cin, input_data[0]);
	std::cout << "Enter the last name: ";
	getline(std::cin, input_data[1]);
	std::cout << "Enter the nickname: ";
	getline(std::cin, input_data[2]);
	std::cout << "Enter the phone number: ";
	getline(std::cin, input_data[3]);
	std::cout << "Enter their darkest secret...: ";
	getline(std::cin, input_data[4]);

	contact->fill_contact(input_data, new_index);


}
void	PhoneBook::display_contacts(PhoneBook *phonebook)
{
	int index  = 0;
	while (index < 8)
	{
		phonebook->contact[index].print_contacts();
		index++;
	}
}

void	PhoneBook::evaluate_answer(PhoneBook *phonebook, std::string answer, int *index, int *counter)
{
	int	search_answer = 0;

	if (*index == 8)
	{
		*index = 0;
		*counter = 1;
	}
	if (answer == "ADD")
		add_contact(&phonebook->contact[(*index)++], counter++);
	if (answer == "SEARCH")
	{
		phonebook->print_contact_header();
		phonebook->display_contacts(phonebook);
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Enter the index of the contact you want to see: ";
		while (search_answer == 0 || !(search_answer > 0 && search_answer < 9))
			std::cin >> search_answer;
		std::cout << std::endl;
		if (phonebook->contact[search_answer - 1].check_contact_exists() == 1)
			std::cout << "There is no such index" << std::endl;
		else
		{
			std::cout << "We have a contact stored at that index!" << std::endl;
			phonebook->contact[search_answer - 1].print_single_contact();
		}
	}
}


