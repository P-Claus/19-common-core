#ifndef FORM_HPP
#define FORM_HPP

#include <ostream>
#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_reqSignGrade;
		const int			_reqExecGrade;
	public:
		//constructors
		Form();
		Form(const std::string name);
		Form(const std::string name, const int reqSignGrade, const int reqExecGrade);
		Form(const Form& other);

		//destructor
		~Form(void);

		//assignment operator overload
		Form& operator=(const Form& rhs);

		//getters
		const std::string	getName(void) const;
		int					getIsSigned(void) const;
		int					getReqSignGrade(void) const;
		int					getReqExecGrade(void) const;

		//misc.
		void				beSigned(Bureaucrat& bureaucrat);

	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};	
};

std::ostream& operator<<(std::ostream& output, Form& rhs);

#endif
