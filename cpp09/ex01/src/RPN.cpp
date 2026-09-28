#include "RPN.hpp"

RPN::RPN(): _stack() {}

RPN::RPN(const std::string &input)
{
	execute(input);
}

RPN::RPN(const RPN &other): _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

RPN::~RPN() {}

void	RPN::execute(const std::string &input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		/*el casteo a unsigned char no es 100% necesario, sin embargo
		aumenta la robustez para el parseo debido a como trabajan
		isdigit e isspace*/
		unsigned char	current = static_cast<unsigned char>(input[i]);

		if (isdigit(current) && (i + 1 == input.length() || isspace(static_cast<unsigned char>(input[i + 1]))))
			_stack.push(current - '0');
		else if (isspace(current))
			continue ;
		else if (isOperator(current)&& (i + 1 == input.length() || isspace(static_cast<unsigned char>(input[i + 1]))))
			calculate(current);
		else
			throw Error("Error");
	}
	if (_stack.size() != 1)
		throw Error("Error");
	else
		std::cout	<< _stack.top() << std::endl;
}

bool	RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void	RPN::calculate(char op)
{
	if (_stack.size() < 2)
		throw Error("Error");
	int	a;
	int	b;
	int	res = 0;
	b = _stack.top();
	_stack.pop();
	a = _stack.top();
	_stack.pop();
	if (op == '+')
		res = a + b;
	else if (op == '-')
		res = a - b;
	else if (op == '*')
		res = a * b;
	else if (op == '/')
	{
		if (b == 0)
			throw Error("Error");
		res = a / b;
	}
	_stack.push(res);
}
