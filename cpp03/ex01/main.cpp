/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:53:20 by ego               #+#    #+#             */
/*   Updated: 2025/08/01 15:56:11 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::string	clapName = "CLAPPY";
	std::string	scavName = "SCAVVY";
	ClapTrap	clap(clapName);
	ScavTrap	scav(scavName);

	std::cout << "\n--- Initial Clash ---" << std::endl;
	clap.attack(scavName);
	scav.takeDamage(clap.getAttackDamage());

	scav.attack(clapName);
	clap.takeDamage(scav.getAttackDamage());

	std::cout << "\n--- Recovery Phase ---" << std::endl;
	clap.beRepaired(5);
	scav.beRepaired(15);

	std::cout << "\n--- ScavTrap enters Gate Keeper Mode ---" << std::endl;
	scav.guardGate();

	std::cout << "\n--- Final Blow ---" << std::endl;
	scav.takeDamage(150);
	scav.attack(clapName);
	scav.guardGate();

	std::cout << "\n--- End of Simulation ---" << std::endl;
	return 0;
}
