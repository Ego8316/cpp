/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:43:34 by ego               #+#    #+#             */
/*   Updated: 2025/09/01 15:35:50 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class	Brain
{
	public:
		Brain(void);
		Brain(Brain const &src);
		Brain	&operator=(Brain const &src);
		~Brain(void);

		void	setIdea(int index, std::string const &idea);
		void	sayIdea(int index) const;

		static int const	nbIdeas = 100;

	private:
		std::string	_ideas[nbIdeas];
};

#endif