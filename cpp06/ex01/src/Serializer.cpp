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

}

Data*		Serializer::deserialize(uintptr_t raw)
{

}

