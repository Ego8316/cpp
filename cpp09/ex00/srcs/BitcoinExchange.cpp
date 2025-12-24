/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:48:02 by ego               #+#    #+#             */
/*   Updated: 2025/12/24 19:11:54 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string	&filename)
	:	_inputFilename(filename)
{
	try { _loadDatabase(); }
	catch (const std::exception &e) { throw std::runtime_error(std::string("could not load database: ") + e.what()); }
	// for (std::map<Date, float>::const_iterator it = _database.begin(); it != _database.end(); ++it)
		// std::cout << it->first.year << "-" << it->first.month << "-" << it->first.day << "\t" << std::fixed << std::setprecision(2) << it->second << std::endl;
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

void	BitcoinExchange::processInput(void) const
{
	std::ifstream	inputFile(_inputFilename.c_str());
	std::string		line;

	if (!inputFile || !inputFile.is_open())
		throw std::runtime_error("could not open file.");
	std::getline(inputFile, line);
	if (line != "date | value")
		throw std::runtime_error("invalid header.");
	while (std::getline(inputFile, line))
	{
		try
		{
			if (line.size() < 14 || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
				throw std::runtime_error("bad input => " + line);
			Date	date = _strToDate(line.substr(0, 10));
			float	value = _strToFloat(line.substr(13));
			if (value > 1000)
				throw std::runtime_error("too large a number.");
			std::cout << date << " => " << value << " = " << value * _getClosestRate(date) << std::endl;
		}
		catch (const std::exception &e) { std::cerr << "Error: " << e.what() << std::endl; }
	}
}

void	BitcoinExchange::_loadDatabase(void)
{
	std::ifstream	databaseFile("data.csv");
	std::string		line;

	if	(!databaseFile || !databaseFile.is_open())
		throw std::runtime_error("could not open database.");
	std::getline(databaseFile, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("invalid header.");
	while (std::getline(databaseFile, line))
	{
		if (line.size() < 12 || line[10] != ',')
			throw std::runtime_error("invalid format.");
		Date	date = _strToDate(line.substr(0, 10));
		float	rate = _strToFloat(line.substr(11));
		std::pair<std::map<Date, float>::iterator, bool> res = _database.insert(std::make_pair(date, rate));
		if (!res.second)
			throw std::runtime_error("duplicate date.");
	}
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

Date	BitcoinExchange::_strToDate(const std::string &s) const
{
	Date	date;

	if (s.size() != 10 || s[4] != '-' || s[7] != '-')
		throw std::runtime_error("bad input => " + s);
	const std::string	&year = s.substr(0, 4);
	const std::string	&month = s.substr(5, 2);
	const std::string	&day = s.substr(8, 2);
	if (!allDigits(year) || !allDigits(month) || !allDigits(day))
		throw std::runtime_error("bad input => " + s);
	date.year = std::atoi(year.c_str());
	date.month = std::atoi(month.c_str());
	date.day = std::atoi(day.c_str());
	if (date.month < 1 || date.month > 12 || date.day < 1
		|| date.day > daysInMonth(date.year, date.month))
		throw std::runtime_error("bad input => " + s);
	return (date);
}

float	BitcoinExchange::_strToFloat(const std::string &s) const
{
	bool	has_dot = false;

	if (s.empty())
		throw std::runtime_error("not a positive number.");
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (std::isdigit(static_cast<unsigned char>(s[i])))
			continue ;
		else if (s[i] == '.' && !has_dot)
			has_dot = true;
		else
			throw std::runtime_error("not a positive number.");
	}
	return (static_cast<float>(std::atof(s.c_str())));
}

float	BitcoinExchange::_getClosestRate(const Date &date) const
{
	std::map<Date, float>::const_iterator it = _database.upper_bound(date);
	if (it != _database.begin())
		--it;
	return (it->second);
}

std::ostream	&operator<<(std::ostream &os, const Date &date)
{
	std::ostream::fmtflags	old_flags = os.flags();
	char					old_fill = os.fill('0');

	os << std::setw(4) << date.year << "-"
		<< std::setw(2) << date.month << "-"
		<< std::setw(2) << date.day;
	os.fill(old_fill);
	os.flags(old_flags);
	return (os);
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

bool	operator>(const Date &lhs, const Date &rhs)
{
	return (!(lhs < rhs) && !(lhs == rhs));
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
