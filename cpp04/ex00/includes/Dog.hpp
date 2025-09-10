/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:50:59 by ego               #+#    #+#             */
/*   Updated: 2025/09/01 21:39:50 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog	:	public	Animal
{
	public:
		Dog(void);
		Dog	&operator=(Dog const &src);
		Dog(Dog const &src);
		~Dog(void);

		void	makeSound(void) const;
};

#endif