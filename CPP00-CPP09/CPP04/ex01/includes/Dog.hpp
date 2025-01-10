#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _dogBrain;
	public:
		//constructor
		Dog(void);

		//destructor
		~Dog(void);

		//copy constructor
		Dog(const Dog& other);

		//=operator overload
		Dog &operator=(const Dog &rhs);

		//misc
		void	makeSound() const;
		void	getAddr() const;
};

#endif