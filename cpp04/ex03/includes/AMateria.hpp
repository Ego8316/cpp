/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:23:47 by ego               #+#    #+#             */
/*   Updated: 2025/10/16 19:07:06 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class	AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(void);
		AMateria(AMateria const &src);
		AMateria(std::string const &type);
		AMateria	&operator=(AMateria const &src);
		virtual ~AMateria(void);

		std::string const	&getType(void) const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
};
