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
		Intern copyIntern(intern);
		AForm* rrrf;

		rrrf = intern.makeForm("presidential pardon", "Bender");
		delete rrrf;

		AForm* a = intern.makeForm("shrubbery creation", "japanese garden");
		delete a;

		AForm* c = intern.makeForm("robotomy request", "Optimus Prime");
		delete c;

		AForm* b = intern.makeForm("lol", "Iraq");
		delete b;

	}

	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

}
