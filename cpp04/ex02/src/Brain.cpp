#include "Brain.hpp"

Brain::Brain() : _ideas()
{
	std::cout	<< "Constructor Default Brain called"
				<< std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	std::cout	<< "Copy Constructor Brain called"
				<< std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout	<< "Destructor Brain called"
				<< std::endl;
}

std::string Brain::getIdea(int index) const
{
	return (this->_ideas[index]);
}

void Brain::setIdea(int index, std::string const & idea)
{
	this->_ideas[index] = idea;
}
