#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
	
	protected:
		std::string	_type;
	public:
		//constructor
		AAnimal(void);

		//destructor
		virtual~AAnimal(void);

		///copy constructor
		AAnimal(const AAnimal& other);

		//=operator overload
		AAnimal &operator=(const AAnimal &rhs);
		
		//getters
		std::string		getType(void) const;
	
		//setters
		void			setType(std::string string);

		//misc
		virtual void	makeSound() const = 0;
};

#endif
