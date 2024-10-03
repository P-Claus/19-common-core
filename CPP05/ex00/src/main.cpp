#include "../includes/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	Bill;
		std::cout << Bill << std::endl;

		Bureaucrat John("John");
		std::cout << John << std::endl;

		Bureaucrat Bob(10);
		std::cout << Bob << std::endl;

		Bureaucrat Jeff = Bob;
		std::cout << Jeff << std::endl;

		Bureaucrat	William("William", 20);
		std::cout << William << std::endl;

		Bureaucrat	Amy("Amy");
		std::cout << Amy << std::endl;
		Bureaucrat	Phoebe = Amy;
		std::cout << Phoebe << std::endl;

		Bill.incrementGrade(100);
		Bill.decrementGrade(20);
		std::cout << Bill << std::endl;

		John.decrementGrade(0);
		John.incrementGrade(30);
		std::cout << John << std::endl;

		Bob.decrementGrade(40);
		Bob.incrementGrade(5);
		std::cout << Bob << std::endl;

		Jeff.decrementGrade(60);
		Jeff.incrementGrade(40);
		std::cout << Jeff << std::endl;

		William.decrementGrade(15);
		William.incrementGrade(34);
		std::cout << William << std::endl;

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
