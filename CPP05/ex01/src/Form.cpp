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
Form::Form(void): _name("default"), _is_signed(false), _req_sign_grade(1), _req_exec_grade(1)
{
	std::cout << "Default constructor for [" << _name << "] has been called" <<std::endl;

}

Form::Form(const std::string name): _name(name), _is_signed(false), _req_sign_grade(1), _req_exec_grade(1)
{
	std::cout << "String constructor for [" << _name << "] has been called" << std::endl;
}

Form::Form(const std::string name, const int req_sign_grade, const int req_exec_grade): _name(name), _is_signed(false), _req_sign_grade(req_sign_grade), _req_exec_grade(req_exec_grade)
{
	if (req_sign_grade < 1 || req_exec_grade < 1)
		throw GradeTooHighException();
	else if (req_sign_grade > 150 || req_exec_grade > 150)
		throw GradeTooLowException();
	else
	{
		std::cout << "Full constructor for [" << _name << "] has been called" << std::endl;
	}
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
	return (_is_signed);
}

int	Form::getReqSignGrade(void) const
{
	return (_req_sign_grade);
}

int	Form::getReqExecGrade(void) const
{
	return (_req_exec_grade);
}

/*	SIGN FUNCTION	*/
void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.signForm(*this) == 1)
		throw GradeTooLowException();
	else
		_is_signed = true;
}

/*	ASSIGNMENT OVERLOAD	*/
Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
	{
		this->_is_signed = rhs._is_signed;
	}
	return (*this);
}

/*	INSERTION OVERLOAD	*/
std::ostream& operator<<(std::ostream& output, Form& rhs)
{
	output << "[" << rhs.getName() << "] -> SIGNED: " << rhs.getIsSigned() << " | GRADE TO SIGN: " << rhs.getReqSignGrade() << " | GRADE TO EXEC: " << rhs.getReqSignGrade() << std::endl;
	return (output);
}

