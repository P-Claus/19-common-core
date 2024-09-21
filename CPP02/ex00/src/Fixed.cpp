#include "../includes/Fixed.hpp"

Fixed::Fixed(void) : fixed_point_nb(0)
{
	std::cout << "Default constructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_nb);
}

void	Fixed::setRawBits(const int raw)
{
	(void)raw;
	std::cout << "setRawBits member function called" << std::endl;
}
