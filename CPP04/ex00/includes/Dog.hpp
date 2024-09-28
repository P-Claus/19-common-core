#include "Animal.hpp"

class Dog : public Animal
{
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
};
