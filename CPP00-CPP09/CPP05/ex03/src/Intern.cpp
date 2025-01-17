#include "../includes/Intern.hpp"

/*	CONSTRUCTORS	*/
Intern::Intern(void)
{
	std::cout << "Default intern constructor has been called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << "Copy constructor for intern has been called" << std::endl;
	(void)other;
}

/*	DESTRUCTOR	*/
Intern::~Intern(void)
{
	std::cout << "The destructor for intern has been called" << std::endl;
}

/*	ASSIGNMENT OPERATOR OVERLOAD	*/
Intern& Intern::operator=(const Intern& rhs)
{
	std::cout << "The assignment operator overload function has been called" << std::endl;
	if (this != &rhs)
	{
		return (*this);
	}
	return (*this);
}

/*	MISC.	*/
AForm* Intern::makeShrubbery(const std::string& target)
{
	std::cout << "Intern creates a ShrubberyCreationForm"<< std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomy(const std::string& target)
{
	std::cout << "Intern creates a RobotomyRequestForm"<< std::endl;
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresident(const std::string& target)
{
	std::cout << "Intern creates a PresidentialPardonForm" << std::endl;
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	AForm*			(Intern::*f[3])(const std::string& target) = { &Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresident };
	int				code = -1;
	std::string 	form[3];

	form[0] = "shrubbery creation";
	form[1] = "robotomy request";
	form[2] = "presidential pardon";

	for (int i = 0; i < 3; i++)
	{
		if (formName == form[i])
			code = i;
	}

	switch (code)
	{
		case 0:
			return (this->*f[0])(target);
		case 1:
			return (this->*f[1])(target);
		case 2:
			return (this->*f[2])(target);
		default:
			std::cout << "Intern cannot create the form because there is no such type of form" << std::endl;
			return (NULL);
	};
}

