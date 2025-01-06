#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream> 
#include <cmath>

class Fixed
{
	private:
		int					_fixedPointNb;
		static const int 	_fractBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int nb);
		Fixed(const float nb);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed& 	operator=(const Fixed& rhs);
		
		//Comparison operators
		bool 	operator==(const Fixed& rhs) const;
		bool 	operator!=(const Fixed& rhs) const;
		bool	operator<(const Fixed& rhs) const;
		bool	operator>(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;
		
		//Arithmetic operators
		Fixed	operator+(const Fixed& rhs);
		Fixed	operator-(const Fixed& rhs);
		Fixed	operator*(const Fixed& rhs);
		Fixed	operator/(const Fixed& rhs);

		//Increment-decrement operators
		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);

		//Min and max functions
		static 			Fixed&	min(Fixed& nb1, Fixed& nb2);
		static const 	Fixed&	min(const Fixed& nb1, const Fixed& nb2);
		static 			Fixed&	max(Fixed& nb1, Fixed& nb2);
		static const 	Fixed&	max(const Fixed& nb1, const Fixed& nb2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif


