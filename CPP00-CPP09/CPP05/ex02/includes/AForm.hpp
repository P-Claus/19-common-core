#ifndef AFORM_HPP
#define AFORM_HPP

#include <ostream>
#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_reqSignGrade;
		const int			_reqExecGrade;
	public:
		//constructors
		AForm(void);
		AForm(const std::string& name, const int reqSignGrade, const int reqExecGrade);
		AForm(const AForm& other);

		//destructor
		~AForm(void);

		//assignment operator overload
		AForm& operator=(const AForm& rhs);

		//getters
		const std::string	getName(void) const;
		int					getIsSigned(void) const;
		int					getReqSignGrade(void) const;
		int					getReqExecGrade(void) const;

		//setters
		void				setIsSigned(bool);

		//misc.
		void				beSigned(Bureaucrat& bureaucrat);
		virtual void		execute(Bureaucrat const& executor) const = 0;	

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
	
	class FormNotSignedException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};	

	class FormAlreadySignedException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};	
};

std::ostream& operator<<(std::ostream& output, AForm& rhs);

#endif
