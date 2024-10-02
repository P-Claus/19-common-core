#include "../includes/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	Bill("Bill", 100);

		Bill.incrementGrade(50);
		Bill.incrementGrade(-30);
		Bill.decrementGrade(20);
		Bill.decrementGrade(70);
		std::cout << Bill << std::endl;

	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}


}
