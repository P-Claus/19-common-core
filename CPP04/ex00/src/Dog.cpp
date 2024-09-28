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

void	Dog::makeSound() const
{
	std::cout << "I am the one who barks" << std::endl;
}
