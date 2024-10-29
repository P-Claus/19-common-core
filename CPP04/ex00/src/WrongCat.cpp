#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "A wrong cat is born..." << std::endl;
	setType("WrongCat");
}

WrongCat::~WrongCat(void)
{
	std::cout << "A wrong cat has died..." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	_type = other._type;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "I am the one who purrs out of tune" << std::endl;
}
