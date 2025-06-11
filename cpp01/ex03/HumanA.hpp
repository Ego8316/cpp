/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:18:12 by ego               #+#    #+#             */
/*   Updated: 2025/06/11 19:39:49 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <iostream>
# include "Weapon.hpp"

class	HumanA
{
	private:
		std::string		_name;
		Weapon const	&_weapon;

	public:
		HumanA(std::string name, Weapon const &weapon);
		~HumanA(void);
		void	attack(void) const;

};

#endif
