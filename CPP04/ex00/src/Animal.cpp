#include "../includes/Animal.hpp"

Animal::Animal(void)
{
	std::cout << "An animal is born..." << std::endl;
	type = "Basic animal";
	getType();
}

Animal::~Animal(void)
{
	std::cout << "An animal has died..." << std::endl;
}

std::string Animal::getType(void) const
{
	std::string	string;
	string = this->type;
	std::cout << "The type is: " << string << std::endl;
	return (string);
}

void	Animal::setType(std::string string)
{
	this->type = string;
}

void	Animal::makeSound() const
{
	std::cout << "This is not an animal sound" << std::endl;
}
