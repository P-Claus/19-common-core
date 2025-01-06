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


WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	_type = other._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::setType(std::string string)
{
	this->_type = string;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Jiiiihaaaaaaa" << std::endl;
}
