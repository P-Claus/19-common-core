#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

/*	EXCEPTIONS	*/
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade you have entered is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade you have entered is too low");
}

/*	CONSTRUCTORS	*/
Bureaucrat::Bureaucrat(void): _name("bot"), _grade(150)
{
	std::cout << "Default constructor has been called for " << this->_name << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150)
{
	std::cout << "String constructor has been called for " << this->_name << std::endl;
}

Bureaucrat::Bureaucrat(int grade): _name("bot"), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		std::cout << "Int constructor has been called for " << this->_name << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) 
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		std::cout << "Full constructor has been called for " << this->_name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other.getName() + "_copy"), _grade(other._grade)
{
	std::cout << "Copy constructor has been called for " << this->_name << std::endl;
}

/*	DESTRUCTORS	*/
Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << Bureaucrat::getName() << " has died..." << std::endl;
}

/*	GETTERS	*/
const std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void)
{
	return (_grade);
}

/*	INCREMENT/DECREMENT FUNCTIONS	*/
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

/*	SIGN FORM	*/
int		Bureaucrat::signForm(Form &form)
{
	if (this->_grade > form.getReqSignGrade())
	{
		std::cout << "[" << this->_name << "] could not sign " << form.getName() << " because his grade is too low" << std::endl;
		return (1);
	}
	else
	{
		std::cout << "[" << this->_name << "] signed " << form.getName() << std::endl;
		return (0);
	}
}

/*	ASSIGNMENT OVERLOAD	*/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return (*this);
}

/*	INSERTION OVERLOAD	*/
std::ostream& operator<<(std::ostream& output, Bureaucrat& rhs)
{
	output << "[" << rhs.getName() << "] grade -> " << rhs.getGrade();
	return (output);
}
