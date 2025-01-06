#include "../includes/Animal.hpp"

Animal::Animal(void) : _type("Basic animal")
{
	std::cout << "An animal is born..." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "An animal has died..." << std::endl;
}

Animal::Animal(const Animal& other)
{
	_type = other._type;
}

Animal& Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::setType(std::string string)
{
	this->_type = string;
}

void	Animal::makeSound() const
{
	std::cout << "This is not an animal sound" << std::endl;
}
