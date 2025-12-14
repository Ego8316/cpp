/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:57:37 by ego               #+#    #+#             */
/*   Updated: 2025/12/14 14:50:37 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <climits>
#include <limits>
#include <cmath>
#include <cstdlib>

class	ScalarConverter
{
	public:
		static void	convert(const std::string &value);

	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter	&operator=(const ScalarConverter &src);
		~ScalarConverter(void);
};
