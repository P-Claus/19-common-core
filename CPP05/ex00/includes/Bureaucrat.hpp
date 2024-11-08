#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <ostream>
#include <string>
#include <iostream>
#include <stdexcept>

class	Bureaucrat
{
	private:
		const std::string 	_name;
		int					_grade;
	public:
		//constructors
		Bureaucrat(void);
		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);

		//destructor
		~Bureaucrat();

		//assignment operator overload
		Bureaucrat& operator=(const Bureaucrat& rhs);

		//getters
		const std::string 	getName(void) const;
		int					getGrade(void);

		//change grade
		void				incrementGrade(int grade);
		void				decrementGrade(int grade);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& output, Bureaucrat& rhs);

#endif
