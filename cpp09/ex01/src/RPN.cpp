#include "RPN.hpp"

RPN::RPN(): _stack() {}

RPN::RPN(const std::string &input) {}

RPN::RPN(const RPN &other)
{

}
RPN &RPN::operator=(const RPN &other)
{

}
RPN::~RPN() {}

void	RPN::execute(const std::string &input)
{

}

bool	RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void	RPN::calculate(char op)
{

}