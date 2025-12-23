/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:48:02 by ego               #+#    #+#             */
/*   Updated: 2025/12/23 16:10:30 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char	*BitcoinExchange::InvalidDateException::what() const throw()
{
	return ("invalid date");
}

const char	*BitcoinExchange::DuplicateDateException::what() const throw()
{
	return ("duplicate date");
}

const char	*BitcoinExchange::InvalidRateException::what() const throw()
{
	return ("invalid rate");
}

const char	*BitcoinExchange::NegativeNumberException::what() const throw()
{
	return ("not a positive number");
}

const char	*BitcoinExchange::NumberTooLargeException::what() const throw()
{
	return ("too large a number");
}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	std::cout << filename << std::endl;
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

static bool	allDigits(const std::string &s)
{
	for (size_t i = 0; i < s.size(); ++i)
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return (false);
	return (true);
}

static bool	isLeapYear(const int y)
{
	return ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));
}

static int	daysInMonth(const int y, const int m)
{
	static const int	days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (m == 2 && isLeapYear(y))
		return (29);
	return (days[m - 1]);
}

Date	BitcoinExchange::_strToDate(const std::string &s)
{
	Date	date;

	if (s.size() != 10 || s[4] != '-' || s[7] != '-')
		throw InvalidDateException();
	const std::string	&year = s.substr(0, 4);
	const std::string	&month = s.substr(5, 2);
	const std::string	&day = s.substr(8, 2);
	if (!allDigits(year) || !allDigits(month) || !allDigits(day))
		throw InvalidDateException();
	date.year = std::atoi(year.c_str());
	date.month = std::atoi(month.c_str());
	date.day = std::atoi(day.c_str());
	if (date.year < 2000 || date.year > 2100 || date.month < 1 || date.month > 12
			|| date.day < 1 || date.day > daysInMonth(date.year, date.month))
		throw InvalidDateException();
	return (date);
}

float	BitcoinExchange::_strToRate(const std::string &s)
{
	float	rate;

	rate = s.size();
	return (rate);
}

bool	operator<(const Date &lhs, const Date &rhs)
{
	if (lhs.year < rhs.year)
		return (true);
	if (lhs.year == rhs.year && lhs.month < rhs.month)
		return (true);
	if (lhs.year == rhs.year && lhs.month == rhs.month
			&& lhs.day < rhs.day)
		return (true);
	return (false);
}

bool	operator==(const Date &lhs, const Date &rhs)
{
	return (lhs.day == rhs.day && lhs.month == rhs.month
				&& lhs.year == rhs.year);
}

bool	operator<=(const Date &lhs, const Date &rhs)
{
	return (lhs == rhs || lhs < rhs);
}
