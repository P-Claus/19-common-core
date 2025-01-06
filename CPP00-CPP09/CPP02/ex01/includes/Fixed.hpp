#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream> 
#include <cmath>
#include <iomanip>

class Fixed
{
	private:
		int					_fixedPointNb;
		static const int 	_fractBits = 8;

	public:
		//constructor
		Fixed();

		//copy constructor
		Fixed(const Fixed& other);

		//copy assignmetn overload
		Fixed& operator=(const Fixed& rhs);

		//destructor
		~Fixed();

		//getter
		int		getRawBits(void) const;

		//setter
		void	setRawBits(int const raw);

		//int consructor
		Fixed(const int nb);

		//float constructor
		Fixed(const float nb);

		//conversion functions
		float	toFloat(void) const;
		int		toInt(void) const;
};

//<< operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif


