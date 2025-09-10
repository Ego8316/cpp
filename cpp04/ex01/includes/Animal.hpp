/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:54:49 by ego               #+#    #+#             */
/*   Updated: 2025/09/01 21:53:12 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class	Animal
{
	protected:
		std::string	_type;

	public:
		Animal(void);
		Animal(std::string const &type);
		Animal(Animal const &src);
		Animal	&operator=(Animal const &src);
		virtual ~Animal(void);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};

#endif