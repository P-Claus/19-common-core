#include "../includes/main.hpp"

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
		phonebook.evaluate_answer(&phonebook, answer, &index, &counter) ;
	}
	if (answer == "EXIT")
	{
		std::cout << "Ending the program and destroying all contacts forever..." << std::endl;
		return (0);
	}
	return (0);
}
