#include "../includes/Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain is created..." << std::endl;
	std::cout << "The address of the brain is: " << this << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain is destroyed..." << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];	
}

Brain& Brain::operator=(const Brain& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}
