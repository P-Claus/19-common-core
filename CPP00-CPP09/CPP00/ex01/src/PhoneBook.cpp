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
	if (std::cin.eof())
		exit(0);
}

int	PhoneBook::add_contact(Contact *contact, int *counter)
{
	std::string	input_data[5];
	int	new_index = *counter;

	std::cin.ignore();
	std::cout << "Enter the first name: ";
	if (getline(std::cin, input_data[0]))
	{
		if (input_data[0].empty())
		{
			std::cout << "The first name can't be empty" << std::endl;
			return (1);
		}
	}
	std::cout << "Enter the last name: ";
	if (getline(std::cin, input_data[1]))
	{
		if (input_data[1].empty())
		{
			std::cout << "The last name can't be empty" << std::endl;
			return (1);
		}
	}
	std::cout << "Enter the nickname: ";
	if (getline(std::cin, input_data[2]))
	{
		if (input_data[2].empty())
		{
			std::cout << "The nickname can't be empty" << std::endl;
			return (1);
		}
	}
	std::cout << "Enter the phone number: ";
	if (getline(std::cin, input_data[3]))
	{
		if (input_data[3].empty())
		{
			std::cout << "The phone number can't be empty" << std::endl;
			return (1);
		}
	}
	std::cout << "Enter their darkest secret...: ";
	if (getline(std::cin, input_data[4]))
	{
		if (input_data[4].empty())
		{
			std::cout << "Their secret can't be empty" << std::endl;
			return (1);
		}
	}
	contact->fill_contact(input_data, new_index);
	(*counter)++;
	return (0);
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

int	PhoneBook::evaluate_answer(PhoneBook *phonebook, std::string answer, int *index, int *counter)
{
	int	search_answer = 0;

	if (*index == 8)
	{
		*index = 0;
		*counter = 1;
	}
	if (answer == "ADD")
	{
		if (add_contact(&phonebook->contact[*index], counter) == 1)
			return (1);
		counter++;
		(*index)++;
	}
	if (answer == "SEARCH")
	{
		phonebook->print_contact_header();
		phonebook->display_contacts(phonebook);
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Enter the index of the contact you want to see: ";
		while (search_answer == 0 || !(search_answer > 0 && search_answer < 9))
		{
			std::cin >> search_answer;
			if (std::cin.eof())
				exit(0);
			if (!std::cin.fail())
				break ;
			else
			{
				std::cout << "Please enter and integer" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		std::cout << std::endl;
		if ((search_answer <= 0 || search_answer > 8) || phonebook->contact[search_answer - 1].check_contact_exists() == 1)
			std::cout << "There is no such index" << std::endl;
		else
		{
			std::cout << "We have a contact stored at that index!" << std::endl;
			phonebook->contact[search_answer - 1].print_single_contact();
		}
	}
	return (0);
}
