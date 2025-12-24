/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:21:06 by ego               #+#    #+#             */
/*   Updated: 2025/12/25 00:10:45 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string &expr)
	:	_input(expr)
{
	return ;
}

float	RPN::processInput(void)
{
	std::istringstream	iss(_input);
	std::string			token;
	while (iss >> token)
	{
		if (token.size() != 1)
			throw std::runtime_error("Error");
		_processToken(token[0]);
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	return (_stack.top());
}

void	RPN::_processToken(const char &c)
{
	if (std::isdigit(static_cast<unsigned char>(c)))
		return (_stack.push(static_cast<float>(c - '0')));
	if (_stack.size() < 2)
		throw std::runtime_error("Error");
	float	a = _popTop();
	float	b = _popTop();
	switch (c)
	{
		case '+':	return (_stack.push(b + a));
		case '-':	return (_stack.push(b - a));
		case '*':	return (_stack.push(b * a));
		case '/':	return (_stack.push(b / a));
		default:	throw std::runtime_error("Error");
	}
}

float	RPN::_popTop(void)
{
	float	value = _stack.top();
	_stack.pop();
	return (value);
}
