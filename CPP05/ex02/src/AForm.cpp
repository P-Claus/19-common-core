#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

/*	EXCEPTIONS	*/
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("The grade you entered is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("The grade you entered is too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("The form is not signed");
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
	return ("The form has already been signed");
}

/*	CONSTRUCTORS	*/

AForm::AForm(void): _name("default"), _isSigned(false), _reqSignGrade(150), _reqExecGrade(150)
{
	std::cout << "| BASE |	Default constructor for [" << _name << "] has been called" <<std::endl;
}

AForm::AForm(const std::string& name, const int reqSignGrade, const int reqExecGrade): _name(name), _reqSignGrade(reqSignGrade), _reqExecGrade(reqExecGrade)
{
	if (reqSignGrade < 1 || reqExecGrade < 1)
		throw GradeTooHighException();
	else if (reqSignGrade > 150 || reqExecGrade > 150)
		throw GradeTooLowException();
	else
	{
		_isSigned = false;
		std::cout << "| BASE |	Full constructor for has been called" << std::endl;
	}
}
AForm::AForm(const AForm& other): _name(other._name + "_copy"), _isSigned(false), _reqSignGrade(other._reqSignGrade), _reqExecGrade(other._reqExecGrade)
{
	std::cout << "The copy constructor for [" << _name << "] has been called" << std::endl;
}

/*	DESTRUCTOR	*/
AForm::~AForm(void)
{
	std::cout << "| BASE |	The destructor has been called" << std::endl;
}

/*	GETTERS	*/
const std::string	AForm::getName(void) const
{
	return (_name);
}

int	AForm::getIsSigned(void) const
{
	return (_isSigned);
}

int	AForm::getReqSignGrade(void) const
{
	return (_reqSignGrade);
}

int	AForm::getReqExecGrade(void) const
{
	return (_reqExecGrade);
}

/*	SETTERS	*/
void	AForm::setIsSigned(bool)
{
	_isSigned = bool();
}

/*	SIGN FUNCTION	*/
void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (this->_isSigned == true)
		throw(FormAlreadySignedException());
	else
	{
		_isSigned = true;
		std::cout << "[" << bureaucrat.getName() << "] signed " << this->_name << "" << std::endl;
	}
}

/*	ASSIGNMENT OVERLOAD	*/
AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

/*	INSERTION OVERLOAD	*/
std::ostream& operator<<(std::ostream& output, AForm& rhs)
{
	output << "[" << rhs.getName() << "] -> SIGNED: " << rhs.getIsSigned() << " | GRADE TO SIGN: " << rhs.getReqSignGrade() << " | GRADE TO EXEC: " << rhs.getReqExecGrade() << std::endl;
	return (output);
}
