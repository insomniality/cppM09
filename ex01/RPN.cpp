#include "RPN.hpp"


void RPN::validator(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
		if ((str[i] < '0' || str[i] > '9') && \
		(str[i] != '-' && str[i] != '+' && str[i] != '/' && str[i] != '*' && !::isspace(str[i])))
			throw (std::runtime_error("Wrong input"));

}

void RPN::motor(std::string str)
{

	for (size_t i = 0; i < str.size(); i++)
	{
		if (::isspace(str[i]))
			continue ;
		if (str[i] >= '0' && str[i] <= '9')
		{
			stk.push(str[i] - 48);
		}
		else
		{
			if (stk.size() < 2)
				throw (std::runtime_error("Wrong input"));

			double b = stk.top();
			stk.pop();
			double a = stk.top();
			stk.pop();

			switch (str[i])
			{
				case '+':
					stk.push(a + b);
					break;		
				case '-':
					stk.push(a - b);
					break;		
				case '/':
					if (b == 0)
						throw (std::runtime_error("Can't divide by 0"));
					stk.push(a / b);
					
					break;		
				case '*':
					stk.push(a * b);
					break;		
				default:
					throw (std::runtime_error("Error"));
					break;
			}

		}
	}
	if (stk.size() != 1)
		throw (std::runtime_error("Error"));
	std::cout << stk.top() << std::endl;
}

//////////

RPN::RPN()
{

}

RPN::RPN(std::string str)
{
	motor(str);
}

RPN::RPN(const RPN& obj)
{
	stk = obj.stk;
}

RPN& RPN::operator=(const RPN& obj)
{
	if (&obj == this)
		return(*this);
	stk = obj.stk;
	return(*this);
}

RPN::~RPN()
{

}