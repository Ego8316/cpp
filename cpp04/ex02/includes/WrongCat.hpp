/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:15:22 by ego               #+#    #+#             */
/*   Updated: 2025/09/01 21:41:04 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat	:	public	WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const &src);
		WrongCat	&operator=(WrongCat const &src);
		~WrongCat(void);

		void	makeSound(void) const;
};

#endif