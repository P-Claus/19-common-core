#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		//constructor
		WrongAnimal(void);

		//destructor
		virtual	~WrongAnimal(void);

		//copy constructor
		WrongAnimal(const WrongAnimal& other);

		//=operator overload
		WrongAnimal &operator=(const WrongAnimal &rhs);
		
		//getters
		std::string		getType(void) const;
	
		//setters
		void			setType(std::string string);

		//misc
		void	makeSound() const;
};

#endif
