#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& src)
{
	(void)src;
}

RPN& RPN::operator=(const RPN& src)
{
	(void)src;
	return (*this);
}

RPN::~RPN() {}

void RPN::exec(std::string input)
{
	if (!validate_input(input))
	{
		std::cerr << "Error" << std::endl;
		return ;
	}
	std::string str;
	std::string new_content;
	int left;
	int right;
	int result;
	std:: stringstream ss;
	for (int i = 0;i < (int)input.size(); i++)
	{
		if (input[i] == ' ')
			continue ;
		if (isdigit(input[i]))
		{
			str = input[i];
			_stack.push(str);
		}
		else
		{
			right = std::atoi(_stack.top().c_str());
			_stack.pop();
			left = std::atoi(_stack.top().c_str());
			_stack.pop();


			if (input[i] == '+')
				result = left + right;
			if (input[i] == '-')
				result = left - right;
			if (input[i] == '/')
				result = left / right;
			if (input[i] == '*')
				result = left * right;
			ss << result;
			ss >> new_content;
			ss.clear();
			_stack.push(new_content);
		}
	}
	if (_stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return;
	}
	std::cout << _stack.top() << std::endl;
}

bool RPN::validate_input(std::string input)
{
	for (int i = 0; i < (int)input.size();i++)
	{
		if (input[i] == ' ' || isdigit(input[i])
		|| input[i] == '+' || input[i] == '-'|| input[i] == '/'|| input[i] == '*')
			continue ;
		else
			return (false);
	}

	int index = 0;
	bool is_digit = false;
	bool is_symbol = false;
	for (int i = 0; i < (int)input.size();i++)
	{
		if (input[i] == ' ')
			continue ;
		else
		{
			if ((index == 0 || index == 1) && !isdigit(input[i]))
				return (false);
			else
			{
				is_digit = true;
				++index;
				continue ;
			}

			if (isdigit((input[i]) && !is_digit))
			{
				is_digit = true;
				is_symbol = false;
			}
			else if ((input[i] == '+' || input[i] == '-'|| input[i] == '/'|| input[i] == '*')
					&& !is_symbol)
			{
				is_digit = false;
				is_symbol = true;
			}
			else
				return (false);
			++index;
		}
	}
	return (true);
}
