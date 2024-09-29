#include "../includes/Animal.hpp"

Animal::Animal(void) : _type("Basic animal")
{
	std::cout << "An animal is born..." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "An animal has died..." << std::endl;
}

Animal& Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

std::string Animal::getType(void) const
{
	std::string	string;
	string = this->_type;
	//std::cout << "The type is: " << string << std::endl;
	return (string);
}

void	Animal::setType(std::string string)
{
	this->_type = string;
}

void	Animal::makeSound() const
{
	std::cout << "This is not an animal sound" << std::endl;
}
