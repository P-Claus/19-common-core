#include "../includes/RobotomyRequestForm.hpp"

static int	robotomy_count = 0;

/*	CONSTRUCTORS	*/
RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("Robotomy", 72, 45), _target(target)
{
	std::cout << "| ROBO |	The constructor has been called and [" << _target << "] is the target" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm("Robotomy_copy", 72, 45), _target(other._target)
{
	std::cout << "| ROBO |	Copy constructor has been called and [" << _target << "] is the target" << std::endl;
}

/*	DESTRUCTOR	*/
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "| ROBO |	The destructor for [" << getName() << "] has been called" << std::endl;
}

/*	ASSIGNMENT OVERLOAD	*/
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	std::cout << "| ROBO |	The assignment operator has been called" << std::endl;
	if (this != &rhs)
		return (*this);
	return (*this);
}

/*	GETTERS	*/
const std::string	RobotomyRequestForm::getTarget(void)
{
	return (_target);
}

/*	INSERTION OVERLOAD	*/
std::ostream& operator<<(std::ostream& output, RobotomyRequestForm& rhs)
{
	output << "||ROBO||	Signed: [" << rhs.getIsSigned() << "] Grade to sign: [" << rhs.getReqSignGrade() << "] Grade to execute: [" << rhs.getReqExecGrade() << "]" << std::endl;
	return (output);
}


/*	MISC.	*/
void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getReqExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == false)
		throw (AForm::FormNotSignedException());
	else if (robotomy_count++ % 2)
		std::cout << "brrrrr bzzzz brrzz... " << "[" << _target << "] has been robotomized" << std::endl; 
	else
		std::cout << "Bleep bloop robotomy failed" << std::endl;
}
