#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <ostream>
#include <string>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	_target;
		//getters
		const std::string	getTarget(void) const;
		ShrubberyCreationForm();
	public:
		//constructors
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);

		//destructor
		~ShrubberyCreationForm();

		//assignment operator overload
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

		//misc.
		virtual void		execute(Bureaucrat const& executor) const;
		AForm*				init(const std::string formName, const std::string target);
};

std::ostream& operator<<(std::ostream& output, ShrubberyCreationForm& rhs);

#endif
