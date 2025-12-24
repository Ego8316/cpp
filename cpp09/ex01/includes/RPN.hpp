/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:19:55 by ego               #+#    #+#             */
/*   Updated: 2025/12/25 00:09:53 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <cctype>
#include <stdexcept>
#include <sstream>

class	RPN
{
	public:
		RPN(const std::string &);

		float	processInput(void);

	private:
		RPN(void);
		RPN(const RPN &);
		RPN	&operator=(const RPN &);

		void	_processToken(const char &);
		float	_popTop(void);

		std::string			_input;
		std::stack<float>	_stack;
};
