#include "../includes/main.hpp"


/*
bool	array_contains_value(Contact array[], int size, int value)
{
	int iter = 0;

	while (iter <= size)
	{
		if (array[iter++] == value)
			return (true);
	}
	return (false);
}

void	add_new_contact(Contact *contact, int *index, int *counter, int *print_counter)
{
	std::string	firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string secret;

	{
		if (*index == 7)
		{
			*index = 0;
			*counter = 1;
		}
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
		contact.fill_contact(*counter, firstName, lastName, nickName, phoneNumber, secret);
		counter++;
		if (*print_counter != 7)
			(*print_counter)++;
		(*index)++;
	}
}
*/

int	main(void)
{
	PhoneBook phonebook;
	std::string answer;
	int	counter = 1;
	int	index = 0;

	phonebook.print_header();
	while (answer != "EXIT")
	{
		phonebook.display_prompt(&answer);
		if (phonebook.evaluate_answer(&phonebook, answer, &index, &counter) == 1)
		break;
	}
	if (answer == "EXIT")
	{
		std::cout << "Ending the program and destroying all contacts forever..." << std::endl;
		return (0);
	}


	return (0);
}
	/*
	PhoneBook phonebook;
	std::string answer;

	int	counter = 1;
	int index = 0;
	int print_counter = 0;
	int	print_index = 0;
	int	search_index;


	while (1)
	{
		if (answer == "ADD")
			//add_new_contact(phonebook.contact[index], &index, &counter, &print_counter);
			std::cout << "ADD" << std::endl;
		else if (answer == "SEARCH")
		{
			std::cout << "SEARCH" << std::endl;
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
//			if (!array_contains_value(phonebook.contact, 7, search_index))
//				std::cout << "Please choose an index that exists...";
			}

		}
		else if (answer != "EXIT" || answer != "ADD" || answer != "SEARCH")
		{
			std::cout << std::endl;
			std::cout << "Please choose ADD, SEARCH or EXIT" << std::endl;
			std::cout << std::endl;
		}

	}


	return 0;
}
*/		
