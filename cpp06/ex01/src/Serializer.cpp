#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &miData)
{
	(void)miData;
}

Serializer	&Serializer::operator=(const Serializer &miData)
{
	(void)miData;
	return (*this);
}


/*TE HAS QUEDADO AQUI*/
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

