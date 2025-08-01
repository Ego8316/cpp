/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:20:06 by ego               #+#    #+#             */
/*   Updated: 2025/08/01 15:29:01 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

# define FRAG_DEFAULT_NAME "FR4G-TV"
# define FRAG_DEFAULT_HIT_POINTS 100
# define FRAG_DEFAULT_ENERGY_POINTS 100
# define FRAG_DEFAULT_ATTACK_DAMAGE 30

class	FragTrap	:	public	ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &src);
		~FragTrap(void);

		FragTrap	&operator=(FragTrap const &src);

		void	attack(std::string const &target);
		void	highFivesGuys(void);
};

#endif