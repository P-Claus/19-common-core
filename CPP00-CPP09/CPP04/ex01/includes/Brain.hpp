#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];
	public:
		//constructor
		Brain(void);

		//destructor
		~Brain(void);

		//copy constructor
		Brain(const Brain& other);

		//=operator overload
		Brain& operator=(const Brain &rhs);
};

#endif
