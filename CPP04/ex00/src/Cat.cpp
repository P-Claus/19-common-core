#include "../includes/Cat.hpp"

Cat::Cat(void)
{
	std::cout << "A cat is born..." << std::endl;
	setType("Cat");
}

Cat::~Cat(void)
{
	std::cout << "A cat has died..." << std::endl;
}

Cat::Cat (const Cat& other)
{
	_type = other._type;
}

Cat &Cat::operator=(const Cat &rhs)
{
	_type = rhs._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "I am the one who purrs" << std::endl;
}
