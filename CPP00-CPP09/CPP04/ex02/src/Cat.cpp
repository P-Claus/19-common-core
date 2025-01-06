#include "../includes/Cat.hpp"

Cat::Cat(void)
{
	std::cout << "A cat is born..." << std::endl;
	setType("Cat");
	_catBrain = new Brain();
}

Cat::~Cat(void)
{
	delete _catBrain;
	std::cout << "A cat has died..." << std::endl;
}

Cat::Cat(const Cat& other): AAnimal(other)
{
	std::cout << "A cat is born..." << std::endl;
	_catBrain = new Brain();
	*_catBrain = *(other._catBrain);
}

Cat& Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		*_catBrain = *rhs._catBrain;
		std::cout << "A catbrain is copied..." << std::endl;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "I am the one who purrs" << std::endl;
}

void	Cat::getAddr() const
{
	std::cout << "Memory address of my brain is: " << this->_catBrain << std::endl;
}
