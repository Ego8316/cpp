/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:36:25 by ego               #+#    #+#             */
/*   Updated: 2025/06/11 01:18:33 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::_trim(const std::string &s)
{
	const std::string	ws = " \t\n\v\f\r";
	size_t				start = s.find_first_not_of(ws);
	size_t				end = s.find_last_not_of(ws);

	if (start == end)
		return ("");
	return (s.substr(start, end - start + 1));
}

bool	Contact::_is_valid_name(const std::string &s)
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

bool	Contact::_is_valid_number(const std::string &s)
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

bool	Contact::set_first_name(const std::string &input)
{
	std::string	first_name = _trim(input);

	if (!_is_valid_name(first_name))
		return (false);
	_first_name = first_name;
	return (true);
}

bool	Contact::set_last_name(const std::string &input)
{
	std::string	last_name = _trim(input);

	if (!_is_valid_name(last_name))
		return (false);
	_last_name = last_name;
	return (true);
}

bool	Contact::set_nickname(const std::string &input)
{
	std::string	nickname = _trim(input);

	if (!_is_valid_name(nickname))
		return (false);
	_nickname = nickname;
	return (true);
}

bool	Contact::set_phone_number(const std::string &input)
{
	std::string	phone_number = _trim(input);

	if (!_is_valid_number(phone_number))
		return (false);
	_phone_number = phone_number;
	return (true);
}

bool	Contact::set_darkest_secret(const std::string &input)
{
	std::string	darkest_secret = _trim(input);

	if (input.empty())
		return (false);
	_darkest_secret = darkest_secret;
	return (true);
}
