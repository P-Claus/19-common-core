#include "../includes/Animal.hpp"

/*	CONSTRUCTOR	*/
Animal::Animal(void) : _type("Basic animal")
{
	std::cout << "An animal is born..." << std::endl;
}

/*	DESTRUCTOR	*/
Animal::~Animal(void)
{
	std::cout << "An animal has died..." << std::endl;
}

/*	COPY CONSTRUCTOR	*/
Animal::Animal(const Animal& other)
{
	_type = other._type;
}

/*	COPY ASSIGNMENT OVERLOAD	*/
Animal &Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

/*	GETTER	*/
std::string Animal::getType(void) const
{
	return (this->_type);
}

/*	SETTER	*/
void	Animal::setType(std::string string)
{
	this->_type = string;
}

/*	MISC.	*/
void	Animal::makeSound() const
{
	std::cout << "This is not an animal sound" << std::endl;
}
