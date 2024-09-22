#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream> 
#include <cmath>

class Fixed
{
	int					fixed_point_nb;
	static const int 	fract_bits = 8;

public:
	Fixed();
	Fixed(const Fixed& ex);
	Fixed& operator=(const Fixed& e);
	Fixed(const int nb);
	Fixed(const float nb);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif


