#ifndef PRESIDENTIALPARDONFORM_HPP 
#define PRESIDENTIALPARDONFORM_HPP

#include <ostream>
#include <string>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;
		PresidentialPardonForm();
		//getters
		const std::string	getTarget(void);
	public:
		//constructors
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);

		//destructor
		~PresidentialPardonForm();

		//assignment operator overload
		PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

		//misc.
		virtual void		execute(Bureaucrat const& executor) const;

};

std::ostream& operator<<(std::ostream& output, PresidentialPardonForm& rhs);

#endif
