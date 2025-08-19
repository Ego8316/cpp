/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:15:22 by ego               #+#    #+#             */
/*   Updated: 2025/08/19 14:50:34 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat	:	public	Animal
{
	public:
		Cat(void);
		Cat(std::string const &type);
		Cat(Cat const &src);
		~Cat(void);
		
		Cat	&operator=(Cat const &src);

		void	makeSound(void) const;
};

#endif