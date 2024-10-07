#ifndef INTERN_HPP
#define INTERN_HPP

#include <ostream>
#include <string>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <fstream>

class Intern 
{
	private:

	public:
		//constructors
		Intern(void);
		//Intern(const Intern& other);

		//destructor
		~Intern(void);
		
		//assignment operator overload
	//	Intern& operator=(const Intern& rhs);

		//misc.
		AForm* makeForm(const std::string& formName, const std::string& target);
		AForm* makeShrubbery(const std::string& target);
		AForm* makeRobotomy(const std::string& target);
		AForm* makePresident(const std::string& target);
};

#endif
