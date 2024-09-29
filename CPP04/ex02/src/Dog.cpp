#include "../includes/Dog.hpp"

Dog::Dog(void)
{
	std::cout << "A dog is born..." << std::endl;
	setType("Dog");
	_dogBrain = new Brain();
}

Dog::~Dog(void)
{
	delete _dogBrain;
	std::cout << "A dog has died..." << std::endl;
}

Dog::Dog(const Dog& other)
{
	std::cout << "A dog is born..." << std::endl;
	_dogBrain = new Brain();
	*_dogBrain = *(other._dogBrain);
}

Dog& Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		*_dogBrain = *rhs._dogBrain;
		std::cout << "A dogbrain is copied..." << std::endl;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "I am the one who barks" << std::endl;
}

void	Dog::getAddr() const
{
	std::cout << "Memory address of my brain is: " << this->_dogBrain << std::endl;
}
