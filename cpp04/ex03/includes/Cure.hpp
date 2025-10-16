/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:32:30 by ego               #+#    #+#             */
/*   Updated: 2025/10/16 19:01:30 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "AMateria.hpp"

class	Cure	:	public	AMateria
{
	public:
		Cure(void);
		Cure(Cure const &src);
		Cure	&operator=(Cure const &src);
		~Cure(void);

		AMateria			*clone(void) const;
		void				use(ICharacter &target);
};
