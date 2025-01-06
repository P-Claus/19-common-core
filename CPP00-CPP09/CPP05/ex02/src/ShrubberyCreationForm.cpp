#include "../includes/ShrubberyCreationForm.hpp"

/*	CONSTRUCTORS	*/
ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("defaultShrubbery", 145, 137), _target("defaultTarget")
{
	std::cout << "| SHCF |	The default constructor has been called and [" << _target << "] is the target" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("Shrubbery", 145, 137), _target(target)
{
	std::cout << "| SHCF |	The constructor has been called and [" << _target << "] is the target" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm("Shrubbery_copy", 145, 137), _target(other._target)
{
	std::cout << "| SHCF |	Copy constructor has been called and [" << _target << "] is the target" << std::endl;
}

/*	DESTRUCTOR	*/
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "| SHCF |	The destructor for [" << getName() << "] has been called" << std::endl;
}

/*	ASSIGNMENT OVERLOAD	*/
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	std::cout << "| SHCF |	The assignment operator has been called" << std::endl;
	if (this != &rhs)
		return (*this);
	return (*this);
}

/*	GETTERS	*/
const std::string	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

/*	INSERTION OVERLOAD	*/
std::ostream& operator<<(std::ostream& output, ShrubberyCreationForm& rhs)
{
	output << "||SHCF||	Signed: [" << rhs.getIsSigned() << "] Grade to sign: [" << rhs.getReqSignGrade() << "] Grade to execute: [" << rhs.getReqExecGrade() << "]" << std::endl;
	return (output);
}

/*	MISC.	*/
void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if(executor.getGrade() > this->getReqExecGrade()) 
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == false)
		throw (AForm::FormNotSignedException());
	else
	{
		std::ofstream outfile ((_target + "_shrubbery").c_str());

		outfile << "         v" << std::endl;
		outfile << "        >X<" << std::endl;
		outfile << "         A" << std::endl;
		outfile << "        d$b" << std::endl;
		outfile << "      .d\\$$b." << std::endl;
		outfile << "    .d$i$$\\$$b." << std::endl;
		outfile << "       d$$@b" << std::endl;
		outfile << "      d\\$$$ib" << std::endl;
		outfile << "    .d$$$\\$$$b" << std::endl;
		outfile << "  .d$$@$$$$\\$$ib." << std::endl;
		outfile << "      d$$i$$b" << std::endl;
		outfile << "     d\\$$$$@$b" << std::endl;
		outfile << "  .d$@$$\\$$$$$@b." << std::endl;
		outfile << ".d$$$$i$$$\\$$$$$$b." << std::endl;
		outfile << "        ###" << std::endl;
		outfile << "        ###" << std::endl;
		outfile << "        ###" << std::endl;

		outfile.close();
	}
}
