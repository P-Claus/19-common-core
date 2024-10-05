#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat Jim("Jim", 60);

		ShrubberyCreationForm newForm("garden");
		std::cout << newForm << std::endl;

		ShrubberyCreationForm copy(newForm);
		std::cout << copy << std::endl;

		RobotomyRequestForm roboForm("factory");
		std::cout << roboForm << std::endl;
		
		RobotomyRequestForm roboCopy(roboForm);
		std::cout << roboCopy << std::endl;

		PresidentialPardonForm presiForm("White House");
		std::cout << presiForm << std::endl;

		PresidentialPardonForm presiCopy(presiForm);
		std::cout << presiCopy << std::endl;

		Jim.signForm(newForm);
		
		std::cout << newForm << std::endl;

		Jim.executeForm(newForm);

		Jim.signForm(roboForm);
		
		std::cout << roboForm << std::endl;

		Jim.executeForm(roboForm);
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
