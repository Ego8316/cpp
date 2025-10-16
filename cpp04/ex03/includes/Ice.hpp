/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:29:36 by ego               #+#    #+#             */
/*   Updated: 2025/10/16 19:01:26 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "AMateria.hpp"

class	Ice	:	public	AMateria
{
	public:
		Ice(void);
		Ice(Ice const &src);
		Ice	&operator=(Ice const &src);
		~Ice(void);

		AMateria			*clone(void) const;
		void				use(ICharacter &target);
};
