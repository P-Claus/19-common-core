#include "../includes/Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade you have entered is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade you have entered is too low");
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) 
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
	{
		_grade = grade;
		std::cout << "Bureaucrat " << Bureaucrat::getName() << " was born with a grade of " << Bureaucrat::getGrade() << std::endl;
	}
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << Bureaucrat::getName() << " has died..." << std::endl;
}

const std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void)
{
	return (_grade);
}

void	Bureaucrat::incrementGrade(int grade)
{
	int	temp(_grade);

	temp -= grade;
	if (temp < 1)
		throw GradeTooHighException();
	else
	{
		_grade -= grade;
		std::cout << Bureaucrat::getName() << "'s new grade is: " << Bureaucrat::getGrade() << " (after -" << grade << ")" << std::endl;
	}
}

void	Bureaucrat::decrementGrade(int grade)
{
	int	temp(_grade);

	temp += grade;
	if (temp > 150)
		throw GradeTooLowException();
	else
	{
		_grade += grade;
		std::cout << Bureaucrat::getName() << "'s new grade is: " << Bureaucrat::getGrade() << " (after +" << grade << ")" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& output, Bureaucrat& rhs)
{
	//output << rhs.getName() << rhs.getGrade();
	output << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (output);
}
