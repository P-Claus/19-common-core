#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "A wrong cat is born..." << std::endl;
	setType("Wrong");
}

WrongCat::~WrongCat(void)
{
	std::cout << "A wrong cat has died..." << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "I am the one who purrs out of tune" << std::endl;
}
