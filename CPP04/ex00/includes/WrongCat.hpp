#include "../includes/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		//constructor
		WrongCat(void);

		//destructor
		~WrongCat(void);

		//copy constructor
		WrongCat(const WrongCat& other);

		//=operator overload
		WrongCat &operator=(const WrongCat &rhs);

		//misc
		void	makeSound() const;
};
