#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Form newForm;
		std::cout << newForm << std::endl;

		Form secondForm("secondForm", 10, 10);
		std::cout << secondForm << std::endl;

		Form thirdForm("thirdForm", 100, 50);
		std::cout << thirdForm << std::endl;

		Bureaucrat	William("William", 20);
		std::cout << William << std::endl;

		thirdForm.beSigned(William);
		std::cout << thirdForm << std::endl;
		
		Bureaucrat Bob("Bob", 10);
		std::cout << Bob << std::endl;

		secondForm.beSigned(Bob);
		std::cout << secondForm << std::endl;
	}

	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

}