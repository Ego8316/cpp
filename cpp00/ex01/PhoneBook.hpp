/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:07:11 by ego               #+#    #+#             */
/*   Updated: 2025/06/11 21:50:36 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "macros.hpp"
# include "Contact.hpp"


class	PhoneBook
{
	private:
		Contact						_contacts[8];
		int							_index;
		int							_size;
		static const std::string	_CMD_ADD;
		static const std::string	_CMD_SEARCH;
		static const std::string	_CMD_EXIT;
		struct	FieldConfig
		{
			const char	*prompt;
			bool		(Contact::*setter)(const std::string &);
			std::string	(Contact::*getter)(void) const;
			const char	*error;
		};
		static const FieldConfig	_fields[];

		bool			_add(void);
		bool			_search(void) const;
		std::string		_format_column(std::string s) const;
		void			_print_columns(void) const;
	
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	print_welcome(void) const;
		void	print_prompt(void) const;
		bool	handle_command(const std::string &cmd);
};

#endif