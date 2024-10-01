#include "../includes/Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade you have entered is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade you have entered is too low");
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) 
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
		else
		{
			_grade = grade;
			std::cout << "A bureaucrat was born!" << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "The exception is: " << e.what() << std::endl;
	}

}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "A bureaucrat has died..." << std::endl;
}
