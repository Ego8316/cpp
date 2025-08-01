/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:53:20 by ego               #+#    #+#             */
/*   Updated: 2025/08/01 16:04:04 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	clap("CLAPPY");
	ScavTrap	scav("SCAVVY");
	FragTrap	frag("FRAGSTER");

	std::cout << "\n--- Round 1: Everyone Attacks ---" << std::endl;
	clap.attack("SCAVVY");
	scav.takeDamage(clap.getAttackDamage());

	scav.attack("FRAGSTER");
	frag.takeDamage(scav.getAttackDamage());

	frag.attack("CLAPPY");
	clap.takeDamage(frag.getAttackDamage());

	std::cout << "\n--- Round 2: Healing Up ---" << std::endl;
	clap.beRepaired(5);
	scav.beRepaired(10);
	frag.beRepaired(20);

	std::cout << "\n--- Round 3: Unique Abilities ---" << std::endl;
	scav.guardGate();
	frag.highFivesGuys();

	std::cout << "\n--- Round 4: Overload ---" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		frag.attack("SCAVVY");
		scav.takeDamage(frag.getAttackDamage());
	}

	clap.beRepaired(10);

	std::cout << "\n--- Final Round: Knockouts ---" << std::endl;
	scav.takeDamage(200);
	scav.attack("CLAPPY");
	frag.highFivesGuys();

	std::cout << "\n--- Simulation Ends ---" << std::endl;
	return 0;
}
