/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:20:24 by ego               #+#    #+#             */
/*   Updated: 2025/10/16 19:27:12 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "ICharacter.hpp"
#include "AMateria.hpp"

class	Character	:	public	ICharacter
{
	protected:
		std::string			_name;
		static const int	_maxSlots = 4;
		AMateria			*_inventory[_maxSlots];

	public:
		Character(void);
		Character(std::string const &name);
		Character(const Character &src);
		Character	&operator=(const Character &src);
		~Character(void);

		std::string const	&getName(void) const;
		AMateria			*getMateria(int idx) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
};
