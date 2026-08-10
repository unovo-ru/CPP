#include "Serializer.hpp"

int	main(void)
{
	Data	*miData = new Data();
	miData->_age = 14;
	miData->_name = "Juanisto";

	std::cout	<< "\n------MEMORY DIRECTION------"
				<< std::endl;
	std::cout	<< miData << std::endl;
	
	std::cout	<< "\n------CONTENT------\n"
				<< "age-> " << miData->_age << std::endl
				<< "name-> " << miData->_name << std::endl
				<< std::endl;

	std::cout	<< "\n------NUMBER CAST------"
				<< std::endl;
	uintptr_t	num = Serializer::serialize(miData);
	std::cout	<< num << std::endl;

	std::cout	<< "\n------MEMORY DIRECTION------"
				<< std::endl;
	miData = Serializer::deserialize(num);
	std::cout	<<miData << std::endl;

	std::cout	<< "\n------CONTENT AGAIN------\n"
				<< "age-> " << miData->_age << std::endl
				<< "name-> " << miData->_name << std::endl
				<< std::endl;

	delete miData;
}