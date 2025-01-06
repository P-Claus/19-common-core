#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

/*	EXCEPTIONS	*/
const char* Form::GradeTooHighException::what() const throw()
{
	return ("The grade you entered is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("The grade you entered is too low");
}

/*	CONSTRUCTORS	*/
Form::Form(void): _name("default"), _isSigned(false), _reqSignGrade(1), _reqExecGrade(1)
{
	std::cout << "Default constructor for [" << _name << "] has been called" <<std::endl;

}

Form::Form(const std::string name): _name(name), _isSigned(false), _reqSignGrade(1), _reqExecGrade(1)
{
	std::cout << "String constructor for [" << _name << "] has been called" << std::endl;
}

Form::Form(const std::string name, const int reqSignGrade, const int reqExecGrade): _name(name), _isSigned(false), _reqSignGrade(reqSignGrade), _reqExecGrade(reqExecGrade)
{
	if (reqSignGrade < 1 || reqExecGrade < 1)
		throw GradeTooHighException();
	else if (reqSignGrade > 150 || reqExecGrade > 150)
		throw GradeTooLowException();
	else
	{
		std::cout << "Full constructor for [" << _name << "] has been called" << std::endl;
	}
}

Form::Form(const Form& other): _name(other._name + "_copy"), _isSigned(false), _reqSignGrade(other._reqSignGrade), _reqExecGrade(other._reqExecGrade)
{
	std::cout << "The copy constructor for [" << _name << "] has been called" << std::endl;
}

/*	DESTRUCTOR	*/
Form::~Form(void)
{
	std::cout << "The destructor for " << _name << " has been called" << std::endl;
}

/*	GETTERS	*/
const std::string	Form::getName(void) const
{
	return (_name);
}

int	Form::getIsSigned(void) const
{
	return (_isSigned);
}

int	Form::getReqSignGrade(void) const
{
	return (_reqSignGrade);
}

int	Form::getReqExecGrade(void) const
{
	return (_reqExecGrade);
}

/*	SIGN FUNCTION	*/
void	Form::beSigned(Bureaucrat& bureaucrat) 
{
	if (bureaucrat.signForm(*this) == 1)
		throw GradeTooLowException();
	else
		_isSigned = true;
}

/*	ASSIGNMENT OVERLOAD	*/
Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

/*	INSERTION OVERLOAD	*/
std::ostream& operator<<(std::ostream& output, Form& rhs)
{
	output << "[" << rhs.getName() << "] -> SIGNED: " << rhs.getIsSigned() << " | GRADE TO SIGN: " << rhs.getReqSignGrade() << " | GRADE TO EXEC: " << rhs.getReqExecGrade() << std::endl;
	return (output);
}

