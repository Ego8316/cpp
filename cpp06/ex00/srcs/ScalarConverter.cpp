/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:28:11 by ego               #+#    #+#             */
/*   Updated: 2025/12/14 15:52:41 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static std::string	formatFloat(double value, bool suffix);
static bool			isPseudoFloat(const std::string &value);
static bool			isPseudoDouble(const std::string &value);
static bool			isChar(const std::string &value);
static bool			isInt(const std::string &value);
static bool			isFloat(const std::string &value);
static bool			isDouble(const std::string &value);
static void			convertChar(const std::string &value);
static void			convertInt(const std::string &value);
static void			convertFloat(const std::string &value);
static void			convertDouble(const std::string &value);
static void			convertPseudo(const std::string &value);

// Private constructors and destructor

ScalarConverter::ScalarConverter(void) { }
ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src) { return ((void)src, *this); }
ScalarConverter::~ScalarConverter(void) { }

static std::string	formatFloat(double value, bool suffix)
{
	std::ostringstream	oss;

	if (std::isnan(value))
		oss << "nan";
	else if (std::isinf(value))
		oss << (value < 0 ? "-inf" : "+inf");
	else if (value == trunc(value))
		oss << std::fixed << std::setprecision(1) << value;
	else
		oss << value;
	if (suffix)
		oss << 'f';
	return (oss.str());
}

static bool	isPseudoFloat(const std::string &value)
{
	return (value == "nanf" || value == "+inff" || value == "-inff");
}

static bool	isPseudoDouble(const std::string &value)
{
	return (value == "nan" || value == "+inf" || value == "-inf");
}

static bool	isChar(const std::string &value)
{
	return (value.size() == 1
		&& std::isprint(static_cast<unsigned char>(value[0]))
		&& !std::isdigit(static_cast<unsigned char>(value[0])));
}

static bool	isInt(const std::string &value)
{
	size_t		i = 0;
	const char	*s = value.c_str();

	if (s[i] == '+' || s[i] == '-')
		++i;
	while (std::isdigit(static_cast<unsigned char>(s[i])))
		++i;
	return (s[i] == '\0');
}

static bool	isFloat(const std::string &value)
{
	size_t		i = 0;
	bool		beforeDot = false;
	bool		afterDot = false;
	const char	*s = value.c_str();

	if (!s[0])
		return (false);
	if (s[i] == '+' || s[i] == '-')
		++i;
	for (; s[i] && std::isdigit(static_cast<unsigned char>(s[i])); ++i)
		beforeDot = true;
	if (!s[i] || s[i] != '.')
		return (false);
	++i;
	for (; s[i] && std::isdigit(static_cast<unsigned char>(s[i])); ++i)
		afterDot = true;
	return (beforeDot && afterDot && s[i] == 'f' && s[i + 1] == '\0');
}

static bool	isDouble(const std::string &value)
{
	size_t		i = 0;
	bool		beforeDot = false;
	bool		afterDot = false;
	const char	*s = value.c_str();

	if (!s[0])
		return (false);
	if (s[i] == '+' || s[i] == '-')
		++i;
	for (; s[i] && std::isdigit(static_cast<unsigned char>(s[i])); ++i)
		beforeDot = true;
	if (!s[i] || s[i] != '.')
		return (false);
	++i;
	for (; s[i] && std::isdigit(static_cast<unsigned char>(s[i])); ++i)
		afterDot = true;
	return (beforeDot && afterDot && s[i] == '\0');
}

void	ScalarConverter::convert(const std::string &value)
{
	if (isChar(value))
		convertChar(value);
	else if (isInt(value))
		convertInt(value);
	else if (isFloat(value))
		convertFloat(value);
	else if (isDouble(value))
		convertDouble(value);
	else if (isPseudoFloat(value) || isPseudoDouble(value))
		convertPseudo(value);
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

static void	convertChar(const std::string &value)
{
	char	c = value[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << formatFloat(static_cast<float>(c), true) << std::endl;
	std::cout << "double: " << formatFloat(static_cast<double>(c), false) << std::endl;
}

static void	convertInt(const std::string &value)
{
	long	lVal = std::strtol(value.c_str(), NULL, 10);

	if (lVal > std::numeric_limits<int>::max() || lVal < std::numeric_limits<int>::min())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << formatFloat(static_cast<float>(lVal), true) << std::endl;
		std::cout << "double: " << formatFloat(static_cast<double>(lVal), false) << std::endl;
		return ;
	}
	int	iVal = static_cast<int>(lVal);

	if (iVal < 0 || iVal > 127)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<unsigned char>(iVal)))
		std::cout << "char: '" << static_cast<char>(iVal) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << iVal << std::endl;
	std::cout << "float: " << formatFloat(static_cast<float>(iVal), true) << std::endl;
	std::cout << "double: " << formatFloat(static_cast<double>(iVal), false) << std::endl;
}

static void	convertFloat(const std::string &value)
{
	double	dVal = std::strtod(value.c_str(), NULL);
	float	fVal = static_cast<float>(dVal);

	if (std::isnan(fVal) || std::isinf(fVal))
		return (convertPseudo(fVal < 0 ? "-inff" : (fVal > 0 ? "+inff" : "nanf")));
	if (fVal < 0 || fVal > 127 || !std::isfinite(fVal))
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<unsigned char>(fVal)))
		std::cout << "char: '" << static_cast<char>(fVal) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (!std::isfinite(fVal) || fVal > std::numeric_limits<int>::max()
		|| fVal < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(fVal) << std::endl;

	std::cout << "float: " << formatFloat(fVal, true) << std::endl;
	std::cout << "double: " << formatFloat(static_cast<double>(fVal), false) << std::endl;
}

static void	convertDouble(const std::string &value)
{
	double	dVal = std::strtod(value.c_str(), NULL);

	if (std::isnan(dVal) || std::isinf(dVal))
	{
		convertPseudo(dVal < 0 ? "-inf" : (dVal > 0 ? "+inf" : "nan"));
		return ;
	}

	if (dVal < 0 || dVal > 127 || !std::isfinite(dVal))
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<unsigned char>(dVal)))
		std::cout << "char: '" << static_cast<char>(dVal) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (!std::isfinite(dVal) || dVal > std::numeric_limits<int>::max()
		|| dVal < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(dVal) << std::endl;

	std::cout << "float: " << formatFloat(static_cast<float>(dVal), true) << std::endl;
	std::cout << "double: " << formatFloat(dVal, false) << std::endl;
}

static void	convertPseudo(const std::string &value)
{
	std::string	floatRep;
	std::string	doubleRep;

	if (value == "nan" || value == "nanf")
	{
		floatRep = "nanf";
		doubleRep = "nan";
	}
	else if (value == "+inf" || value == "+inff")
	{
		floatRep = "+inff";
		doubleRep = "+inf";
	}
	else
	{
		floatRep = "-inff";
		doubleRep = "-inf";
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << floatRep << std::endl;
	std::cout << "double: " << doubleRep << std::endl;
}
