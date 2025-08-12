/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:53:20 by ego               #+#    #+#             */
/*   Updated: 2025/08/12 13:10:27 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diamondTrap("DIAMOND");

	diamondTrap.whoAmI();
	diamondTrap.attack("anyone");
	diamondTrap.highFivesGuys();
	diamondTrap.takeDamage(150);
	diamondTrap.guardGate();
	diamondTrap.whoAmI();
}
