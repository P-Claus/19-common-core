#include "../includes/Cat.hpp"

Cat::Cat(void)
{
	std::cout << "A cat is born..." << std::endl;
	setType("Cat");
	getType();

}

Cat::~Cat(void)
{
	std::cout << "A cat has died..." << std::endl;
}
