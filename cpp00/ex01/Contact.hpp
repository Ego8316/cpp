/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:07:59 by ego               #+#    #+#             */
/*   Updated: 2025/06/12 13:54:56 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <sstream>
#include <string>

class	Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;

		std::string	_trim(std::string const &s) const;
		bool		_is_valid_name(std::string const &s) const;
		bool		_is_valid_number(std::string const &s) const;
		std::string	_format_column(std::string s) const;

	public:
		Contact(void);
		~Contact(void);

		std::string		get_first_name(void) const;
		std::string		get_last_name(void) const;
		std::string		get_nickname(void) const;
		std::string		get_phone_number(void) const;
		std::string		get_darkest_secret(void) const;
		bool			set_first_name(const std::string &input);
		bool			set_last_name(const std::string &input);
		bool			set_nickname(const std::string &input);
		bool			set_phone_number(const std::string &input);
		bool			set_darkest_secret(const std::string &input);
};

#endif