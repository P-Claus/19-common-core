#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int	main(void)
{
	try
	{
		Intern intern;

		AForm* rrrf;

		rrrf = intern.makeForm("presidential pardon", "Bender");

		std::cout << rrrf << std::endl;

		delete rrrf;

		AForm* a = intern.makeForm("shrubbery creation", "japanese garden");

		std::cout << a << std::endl;

		delete a;


		AForm* b = intern.makeForm("lol", "Iraq");

		std::cout << b << std::endl;

		delete b;

	}

	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const AForm::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const AForm::FormNotSignedException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const AForm::FormAlreadySignedException& e)
	{
		std::cout << e.what() << std::endl;
	}

}
