#include "../includes/Fixed.hpp"

Fixed::Fixed(void) : _fixedPointNb(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb)
{
	//std::cout << "Constructor with const int as argument is called" << std::endl;
	setRawBits(nb << 8);
}

Fixed::Fixed(const float nb)
{
	//std::cout << "Constructor with const float as argument is called" << std::endl;
	setRawBits(roundf(nb * 256));
}

Fixed::~Fixed(void)
{
	//std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	_fixedPointNb = other._fixedPointNb;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	//std::cout << "Copy assignment operator called" << std::endl;
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

bool Fixed::operator==(const Fixed& rhs) const
{
	return (this->_fixedPointNb == rhs._fixedPointNb);
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return (!(*this == rhs));
}

bool Fixed::operator<(const Fixed& rhs) const
{
	return (this->_fixedPointNb < rhs._fixedPointNb);
}

bool Fixed::operator>(const Fixed& rhs) const
{
	return (this->_fixedPointNb > rhs._fixedPointNb);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_fixedPointNb < rhs._fixedPointNb || this->_fixedPointNb == rhs._fixedPointNb);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_fixedPointNb > rhs._fixedPointNb || this->_fixedPointNb == rhs._fixedPointNb);
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
	_fixedPointNb++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	_fixedPointNb++;
	return (temp);
}

Fixed Fixed::operator--()
{
	if (_fixedPointNb > 1)
		_fixedPointNb--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	if (_fixedPointNb > 1)
		_fixedPointNb--;
	return (temp);
}

Fixed& Fixed::min(Fixed& nb1, Fixed& nb2)
{
	if (nb1._fixedPointNb < nb2._fixedPointNb)
		return (nb1);
	else
	 return (nb2);
}

const Fixed& Fixed::min(const Fixed& nb1, const Fixed& nb2)
{

	if (nb1._fixedPointNb < nb2._fixedPointNb)
		return (nb1);
	else
		return (nb2);
}

Fixed& Fixed::max(Fixed& nb1, Fixed& nb2)
{
	if (nb1._fixedPointNb > nb2._fixedPointNb)
		return (nb1);
	else
	 return (nb2);
}

const Fixed& Fixed::max(const Fixed& nb1, const Fixed& nb2)
{

	if (nb1._fixedPointNb > nb2._fixedPointNb)
		return (nb1);
	else
		return (nb2);
}
