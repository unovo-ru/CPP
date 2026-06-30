#include "Animal.hpp"

Animal::Animal(){}

Animal::~Animal(){}

Animal::Animal(std::string const &type) : _type(type)
{

}
Animal::Animal(Animal const &src)
{

}
Animal& Animal::operator=(Animal const &src)
{

}


std::string	Animal::getType() const
{

}
void	Animal::makeSound() const
{

}
