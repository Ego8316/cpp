/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:07:59 by ego               #+#    #+#             */
/*   Updated: 2025/06/10 19:09:34 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class	Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;

		std::string	_trim(std::string const &s);
		bool		_is_valid_name(std::string const &s);
		bool		_is_valid_number(std::string const &s);
	
	public:
		Contact(void);
		~Contact(void);

		bool	set_first_name(const std::string &input);
		bool	set_last_name(const std::string &input);
		bool	set_nickname(const std::string &input);
		bool	set_phone_number(const std::string &input);
		bool	set_darkest_secret(const std::string &input);
};

#endif