/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:07:11 by ego               #+#    #+#             */
/*   Updated: 2025/06/10 18:10:13 by ego              ###   ########.fr       */
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
		static const	std::string CMD_ADD;
		static const	std::string CMD_SEARCH;
		static const	std::string CMD_EXIT;
	
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	printWelcome(void);
		void	printPrompt(void);
		bool	handleCommand(const std::string &cmd);
};

#endif