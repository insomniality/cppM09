#pragma once

#include <iostream>
#include <stack>


class RPN
{
	private:
		std::stack<double> stk;
	public:
		void motor(std::string);
		void validator(std::string str);
	public:
		RPN();
		RPN(std::string);
		RPN(const RPN&);
		RPN& operator=(const RPN&);
		~RPN();
};
