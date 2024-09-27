#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	
	private:
		std::string	type;
	public:
		//constructor
		Animal(void);

		//destructor
		~Animal(void);

		///copy constructor
		Animal(const Animal& other);

		//=operator overload
		Animal &operator=(const Animal &rhs);
		
		//getters
		std::string		getType(void) const;
	
		//setters
		void			setType(std::string string);

		//misc
		virtual void	makeSound() const;
};

#endif
