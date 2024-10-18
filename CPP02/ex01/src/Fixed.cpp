#include "../includes/Fixed.hpp"

Fixed::Fixed(void) : _fixedPointNb(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor is called" << std::endl;
	setRawBits(nb << 8);
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor is called" << std::endl;
	setRawBits(roundf(nb * 256));
}

Fixed::~Fixed(void)
{
	std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	_fixedPointNb = other._fixedPointNb;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		_fixedPointNb = rhs._fixedPointNb;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPointNb);
}

void	Fixed::setRawBits(const int raw)
{
	_fixedPointNb = raw;
}

float	Fixed::toFloat(void) const
{
	float nb = _fixedPointNb / 256.0f;
	return (nb);
}

int		Fixed::toInt(void) const
{
	int	nb = _fixedPointNb >> 8;
	return (nb);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
