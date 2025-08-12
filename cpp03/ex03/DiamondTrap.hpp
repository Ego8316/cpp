/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:21:09 by ego               #+#    #+#             */
/*   Updated: 2025/08/12 12:54:34 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap	:	public	FragTrap,	public	ScavTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string const &name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap(void);

		DiamondTrap	&operator=(DiamondTrap const &src);

		using	ScavTrap::attack;
		void	whoAmI(void);

	private:
		std::string	_name;
};

#endif