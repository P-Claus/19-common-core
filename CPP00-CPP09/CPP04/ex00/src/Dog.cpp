#include "../includes/Dog.hpp"

Dog::Dog(void)
{
	std::cout << "A dog is born..." << std::endl;
	setType("Dog");
}

Dog::~Dog(void)
{
	std::cout << "A dog has died..." << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
	_type = other._type;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "I am the one who barks" << std::endl;
}
