/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:41:41 by ego               #+#    #+#             */
/*   Updated: 2025/12/22 18:07:25 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <map>

struct	Date
{
	int	day;
	int	month;
	int	year;
};

class	BitcoinExchange
{
	public:
		BitcoinExchange(const std::string &);
		~BitcoinExchange(void);

		class	InvalidDateException	:	public	std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	DuplicateDateException	:	public	std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	InvalidRateException	:	public	std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	NegativeNumberException	:	public	std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	NumberTooLargeException	:	public	std::exception
		{
			public:
				const char	*what() const throw();
		};

	private:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &);
		BitcoinExchange	&operator=(const BitcoinExchange &);

		std::map<Date, float>	_database;

		Date	_strToDate(const std::string &);
		float	_strToRate(const std::string &);
};

bool	operator<(const Date &, const Date &);
bool	operator==(const Date &, const Date &);
bool	operator<=(const Date &, const Date &);
