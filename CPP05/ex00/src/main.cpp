#include "../includes/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	Bill("Bill", 50);
		std::cout << Bill << std::endl;

		std::cout << Bill.getName() << std::endl;

		Bill.incrementGrade(20);

		std::cout << Bill.getGrade() << std::endl;

		Bill.decrementGrade(30);

		std::cout << Bill.getGrade() << std::endl;

		Bill.incrementGrade(200);

		//Bureaucrat John("John", 160);
		//std::cout << John << std::endl;

		//Bureaucrat Amy("Amy", 0);
		//std::cout << Amy << std::endl;

	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
