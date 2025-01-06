#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

struct Data
{
	int		nb;
};

class Serializer
{
	private:
		//constructor
		Serializer();
		//destructor
		~Serializer();
		//copy constructor
		Serializer(const Serializer& other);
		//assignment overload
		Serializer operator=(const Serializer& rhs);	
	public:
		static uintptr_t 	serialize(Data* ptr);
		static Data* 		deserialize(uintptr_t raw);
};

#endif
