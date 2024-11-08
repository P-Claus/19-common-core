#ifndef ROBOTOMYREQUESTFORM_HPP 
#define ROBOTOMYREQUESTFORM_HPP

#include <ostream>
#include <string>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;
		RobotomyRequestForm();
		//getters
		const std::string	getTarget(void);
	public:
		//constructors
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);

		//destructor
		~RobotomyRequestForm();

		//assignment operator overload
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

		//misc.
		virtual void		execute(Bureaucrat const& executor) const;

};

std::ostream& operator<<(std::ostream& output, RobotomyRequestForm& rhs);

#endif
