/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:41:41 by ego               #+#    #+#             */
/*   Updated: 2025/12/24 18:58:47 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <utility>
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

		void	processInput(void) const;

	private:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &);
		BitcoinExchange	&operator=(const BitcoinExchange &);

		std::map<Date, float>	_database;
		std::string				_inputFilename;

		void	_loadDatabase(void);
		Date	_strToDate(const std::string &) const;
		float	_strToFloat(const std::string &) const;
		float	_getClosestRate(const Date &) const;
};

std::ostream	&operator<<(std::ostream &, const Date &);
bool			operator<(const Date &, const Date &);
bool			operator>(const Date &, const Date &);
bool			operator==(const Date &, const Date &);
bool			operator<=(const Date &, const Date &);
