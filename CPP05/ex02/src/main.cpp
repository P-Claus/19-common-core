#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat Jim("Jim", 3);

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

		Jim.signForm(presiCopy);

		std::cout << presiCopy << std::endl;

		Jim.executeForm(presiCopy);
	}

	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}
