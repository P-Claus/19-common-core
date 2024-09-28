#include "../includes/Animal.hpp"

class Cat : public Animal
{
	public:
		//constructor
		Cat(void);

		//destructor
		~Cat(void);

		//copy constructor
		Cat(const Cat& other);

		//=operator overload
		Cat &operator=(const Cat &rhs);

		//misc
		void	makeSound() const;
};
