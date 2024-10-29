#include "../includes/AAnimal.hpp"

AAnimal::AAnimal(void) : _type("Basic animal")
{
	std::cout << "An animal is born..." << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "An animal has died..." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
	_type = other._type;
}

AAnimal& AAnimal::operator=(const AAnimal &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}

void	AAnimal::setType(std::string string)
{
	this->_type = string;
}

void	AAnimal::makeSound() const
{
	std::cout << "This is not an animal sound" << std::endl;
}
