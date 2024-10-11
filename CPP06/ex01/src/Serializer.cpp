#include "../includes/Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t uintPtr = reinterpret_cast<uintptr_t>(ptr);	
	return (uintPtr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	Data *dataPtr = reinterpret_cast<Data *>(raw);
	return (dataPtr);
}
