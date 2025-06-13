/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:53:20 by ego               #+#    #+#             */
/*   Updated: 2025/06/13 17:04:47 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "--- Creating ClapTrap A (R2D2) ---" << std::endl;
	ClapTrap A("R2D2");

	std::cout << "--- Creating ClapTrap B (C3PO) ---" << std::endl;
	ClapTrap B("C3PO");

	std::cout << "--- A attacks B ---" << std::endl;
	A.attack(B.getName());

	std::cout << "--- B takes damage ---" << std::endl;
	B.takeDamage(3);

	std::cout << "--- B repairs itself ---" << std::endl;
	B.beRepaired(5);

	std::cout << "--- B repairs itself to max HP ---" << std::endl;
	B.beRepaired(100); // should hit max cap and print "already at full"

	std::cout << "--- A attacks B until out of energy ---" << std::endl;
	for (int i = 0; i < 11; i++) // one more than energy points
		A.attack(B.getName());

	std::cout << "--- A tries to repair with no energy ---" << std::endl;
	A.beRepaired(3); // no energy left message

	std::cout << "--- B takes fatal damage ---" << std::endl;
	B.takeDamage(100); // dies

	std::cout << "--- B takes damage while defunct ---" << std::endl;
	B.takeDamage(100); // leave him be!

	std::cout << "--- B tries to attack while defunct ---" << std::endl;
	B.attack(A.getName()); // dead cannot attack

	std::cout << "--- B tries to repair while defunct ---" << std::endl;
	B.beRepaired(5); // dead cannot repair

	std::cout << "--- Copy constructor test ---" << std::endl;
	ClapTrap C(A); // copy of exhausted A
	C.attack("someone"); // should also have no energy

	std::cout << "--- Assignment operator test ---" << std::endl;
	ClapTrap D("NEWBIE");
	D = B; // assign dead B to D
	D.attack("someone"); // D is now also defunct
	return (0);
}
