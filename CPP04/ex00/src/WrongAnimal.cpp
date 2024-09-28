#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
		std::cout << "A wrong animal is born..." << std::endl;
		setType("Wrong");
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "A wrong animal has died..." << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	std::string	string;
	string = this->_type;
	return (string);
}

void	WrongAnimal::setType(std::string string)
{
	this->_type = string;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Jiiiihaaaaaaa" << std::endl;
}
