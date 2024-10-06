#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

/*	CONSTRUCTORS	*/
PresidentialPardonForm::PresidentialPardonForm(void): AForm("defaultPresi", 25, 5), _target("defaultTarget")
{
	std::cout << "| PRES |	The default constructor has been called and [" << _target << "] is the target" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("Presidential", 25, 5), _target(target)
{
	std::cout << "| PRES |	The constructor has been called and [" << _target << "] is the target" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm("Presidential_copy", 25, 5), _target(other._target)
{
	std::cout << "| PRES |	Copy constructor has been called and [" << _target << "] is the target" << std::endl;
}

/*	DESTRUCTOR	*/
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "| PRES |	The destructor for [" << getName() << "] has been called" << std::endl;
}

/*	ASSIGNMENT OVERLOAD	*/
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	std::cout << "| PRES |	The assignment operator has been called" << std::endl;
	if (this != &rhs)
		return (*this);
	return (*this);
}

/*	GETTERS	*/
const std::string	PresidentialPardonForm::getTarget(void)
{
	return (_target);
}

/*	INSERTION OVERLOAD	*/
std::ostream& operator<<(std::ostream& output, PresidentialPardonForm& rhs)
{
	output << "||PRES||	Signed: [" << rhs.getIsSigned() << "] Grade to sign: [" << rhs.getReqSignGrade() << "] Grade to execute: [" << rhs.getReqExecGrade() << "]" << std::endl;
	return (output);
}

/*	MISC.	*/
void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getReqExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == false)
		throw (AForm::FormNotSignedException());
	else
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
