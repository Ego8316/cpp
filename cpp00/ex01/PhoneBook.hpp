/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:07:11 by ego               #+#    #+#             */
/*   Updated: 2025/06/10 18:39:04 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "colors.hpp"
# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact			_contacts[8];
		int				_index;
		static const	std::string _CMD_ADD;
		static const	std::string _CMD_SEARCH;
		static const	std::string _CMD_EXIT;
	
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	print_welcome(void);
		void	print_prompt(void);
		bool	handle_command(const std::string &cmd);
		void	add_contact(void);
};

#endif