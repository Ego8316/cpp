/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:36:25 by ego               #+#    #+#             */
/*   Updated: 2025/06/11 14:53:33 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/**
 * @brief Default constructor for Contact.
 */
Contact::Contact(void)
{
	return ;
}

/**
 * @brief Destructor for Contact.
 */
Contact::~Contact(void)
{
	return ;
}

/**
 * @brief Trims leading and trailing whitespace characters from a string.
 * 
 * @param s The input string to trim.
 * 
 * @return A trimmed copy of the input string.
 */
std::string	Contact::_trim(const std::string &s) const
{
	const std::string	ws = " \t\n\v\f\r";
	size_t				start = s.find_first_not_of(ws);
	size_t				end = s.find_last_not_of(ws);

	if (start == std::string::npos)
		return ("");
	return (s.substr(start, end - start + 1));
}

/**
 * @brief Checks if the provided string is a valid name.
 * 
 * A valid name contains only alphabetic characters, spaces, hyphens or apostrophes.
 * 
 * @param s The string to validate.
 * 
 * @return true if valid, false otherwise.
 */
bool	Contact::_is_valid_name(const std::string &s) const
{
	if (s.empty())
		return (false);
	for (std::string::const_iterator i = s.begin(); i != s.end(); ++i)
	{
		if (!std::isalpha(*i) && !std::isspace(*i) && *i != '-' && *i != '\'')
			return (false);
	}
	return (true);
}

/**
 * @brief Checks if the provided string is a valid phone number.
 * 
 * A valid phone number may start with '+' followed by digits only.
 * 
 * @param s The string to validate.
 * 
 * @return true if valid, false otherwise.
 */
bool	Contact::_is_valid_number(const std::string &s) const
{
	if (s.empty())
		return (false);
	std::string::const_iterator i = s.begin();
	if (i != s.end() && *i == '+')
		++i;
	if (i == s.end())
		return (false);
	for (; i != s.end(); ++i)
	{
		if (!std::isdigit(*i))
			return (false);
	}
	return (true);
}

/**
 * @brief Retrieves the first name of the contact.
 * 
 * @return The first name string.
 */
std::string	Contact::get_first_name(void) const
{
	return (_first_name);
}

/**
 * @brief Retrieves the last name of the contact.
 * 
 * @return The last name string.
 */
std::string	Contact::get_last_name(void) const
{
	return (_last_name);
}

/**
 * @brief Retrieves the nickname of the contact.
 * 
 * @return The last name string.
 */
std::string	Contact::get_nickname(void) const
{
	return (_nickname);
}

/**
 * @brief Retrieves the phone number of the contact.
 * 
 * @return The phone number string.
 */
std::string	Contact::get_phone_number(void) const
{
	return (_phone_number);
}

/**
 * @brief Retrieves the darkest secret of the contact.
 * 
 * @return The darkest secret string.
 */
std::string	Contact::get_darkest_secret(void) const
{
	return (_darkest_secret);
}

/**
 * @brief Sets the first name after validation and trimming.
 * 
 * @param input The input string to set as first name.
 * 
 * @return true if the input is valid and set successfully, false otherwise.
 */
bool	Contact::set_first_name(const std::string &input)
{
	std::string	first_name = _trim(input);

	if (!_is_valid_name(first_name))
		return (false);
	_first_name = first_name;
	return (true);
}

/**
 * @brief Sets the last name after validation and trimming.
 * 
 * @param input The input string to set as last name.
 * 
 * @return true if the input is valid and set successfully, false otherwise.
 */
bool	Contact::set_last_name(const std::string &input)
{
	std::string	last_name = _trim(input);

	if (!_is_valid_name(last_name))
		return (false);
	_last_name = last_name;
	return (true);
}

/**
 * @brief Sets the nickname after validation and trimming.
 * 
 * @param input The input string to set as nickname.
 * 
 * @return true if the input is valid and set successfully, false otherwise.
 */
bool	Contact::set_nickname(const std::string &input)
{
	std::string	nickname = _trim(input);

	if (!_is_valid_name(nickname))
		return (false);
	_nickname = nickname;
	return (true);
}

/**
 * @brief Sets the phone number after validation and trimming.
 * 
 * @param input The input string to set as phone number.
 * 
 * @return true if the input is valid and set successfully, false otherwise.
 */
bool	Contact::set_phone_number(const std::string &input)
{
	std::string	phone_number = _trim(input);

	if (!_is_valid_number(phone_number))
		return (false);
	_phone_number = phone_number;
	return (true);
}

/**
 * @brief Sets the darkest secret after trimming.
 * 
 * @param input The input string to set as darkest secret.
 * 
 * @return true if the input is not empty and set successfully, false otherwise.
 */
bool	Contact::set_darkest_secret(const std::string &input)
{
	std::string	darkest_secret = _trim(input);

	if (input.empty())
		return (false);
	_darkest_secret = darkest_secret;
	return (true);
}
