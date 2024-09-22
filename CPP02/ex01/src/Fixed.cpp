#include "../includes/Fixed.hpp"

Fixed::Fixed(void) : fixed_point_nb(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Constructor with const int as argument is called" << std::endl;
	setRawBits(nb << 8);
}

Fixed::Fixed(const float nb)
{
	std::cout << "Constructor with const float as argument is called" << std::endl;
	setRawBits(roundf(nb * 256));
}

Fixed::~Fixed(void)
{
	std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ex)
{
	std::cout << "Copy constructor called" << std::endl;
	fixed_point_nb = ex.fixed_point_nb;
}

Fixed& Fixed::operator=(const Fixed& e)
{
	std::cout << "Copy assignment operator called" << std::endl;
	fixed_point_nb = e.fixed_point_nb;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->fixed_point_nb);
}

void	Fixed::setRawBits(const int raw)
{
	fixed_point_nb = raw;
}

float	Fixed::toFloat(void) const
{
	float nb = fixed_point_nb / 256.0;
	return (nb);
}

int		Fixed::toInt(void) const
{
	int	nb = fixed_point_nb >> 8;
	return (nb);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
