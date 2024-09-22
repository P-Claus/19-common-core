#include "../includes/Fixed.hpp"

Fixed::Fixed(void) : fixed_point_nb(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb)
{
//	std::cout << "Constructor with const int as argument is called" << std::endl;
	setRawBits(nb << 8);
}

Fixed::Fixed(const float nb)
{
//	std::cout << "Constructor with const float as argument is called" << std::endl;
	setRawBits(roundf(nb * 256));
}

Fixed::~Fixed(void)
{
//	std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ex)
{
//	std::cout << "Copy constructor called" << std::endl;
	fixed_point_nb = ex.fixed_point_nb;
}

Fixed& Fixed::operator=(const Fixed& e)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &e)
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

bool Fixed::operator==(const Fixed& rhs) const
{
	return (this->fixed_point_nb == rhs.fixed_point_nb);
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return (!(*this == rhs));
}

bool Fixed::operator<(const Fixed& rhs) const
{
	return (this->fixed_point_nb < rhs.fixed_point_nb);
}

bool Fixed::operator>(const Fixed& rhs) const
{
	return (this->fixed_point_nb > rhs.fixed_point_nb);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->fixed_point_nb < rhs.fixed_point_nb || this->fixed_point_nb == rhs.fixed_point_nb);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->fixed_point_nb > rhs.fixed_point_nb || this->fixed_point_nb == rhs.fixed_point_nb);
}

Fixed Fixed::operator+(const Fixed& rhs)
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rhs)
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed& rhs)
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs)
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed Fixed::operator++()
{
	fixed_point_nb++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	fixed_point_nb++;
	return (temp);
}

Fixed Fixed::operator--()
{
	if (fixed_point_nb > 1)
		fixed_point_nb--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	if (fixed_point_nb > 1)
		fixed_point_nb--;
	return (temp);
}

Fixed& Fixed::min(Fixed& nb1, Fixed& nb2)
{
	if (nb1.fixed_point_nb < nb2.fixed_point_nb)
		return (nb1);
	else
	 return (nb2);
}

const Fixed& Fixed::min(const Fixed& nb1, const Fixed& nb2)
{

	if (nb1.fixed_point_nb < nb2.fixed_point_nb)
		return (nb1);
	else
		return (nb2);
}

Fixed& Fixed::max(Fixed& nb1, Fixed& nb2)
{
	if (nb1.fixed_point_nb > nb2.fixed_point_nb)
		return (nb1);
	else
	 return (nb2);
}

const Fixed& Fixed::max(const Fixed& nb1, const Fixed& nb2)
{

	if (nb1.fixed_point_nb > nb2.fixed_point_nb)
		return (nb1);
	else
		return (nb2);
}
