#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class	Bureaucrat
{
	private:
		const std::string 	_name;
		int					_grade;
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		const std::string getName(void) const;
		int	getGrade(int grade);
		void	incrementGrade(int	grade);
		void	decremenrGrade(int grade);

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

#endif
