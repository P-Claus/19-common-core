#include <iostream>

class Fixed
{
	int					fixed_point_nb;
	static const int 	fract_bits = 8;

public:
	Fixed();
	Fixed(const Fixed& ex);
	Fixed& operator=(const Fixed& e);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
