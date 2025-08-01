/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:03:48 by ego               #+#    #+#             */
/*   Updated: 2025/06/13 18:53:55 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

# define SCAV_DEFAULT_NAME "SC4V-TP"
# define SCAV_DEFAULT_HIT_POINTS 100
# define SCAV_DEFAULT_ENERGY_POINTS 50
# define SCAV_DEFAULT_ATTACK_DAMAGE 20

class	ScavTrap	:	public	ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &src);
		~ScavTrap(void);

		ScavTrap	&operator=(ScavTrap const &src);

		void	attack(std::string const &target);
		void	guardGate(void);
};

#endif