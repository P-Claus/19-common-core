#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _catBrain;
	public:
		//constructor
		Cat(void);

		//destructor
		~Cat(void);

		//copy constructor
		Cat(const Cat& other);

		//=operator overload
		Cat& operator=(const Cat &rhs);

		//misc
		void	makeSound() const;
		void	getAddr() const;
};

#endif
