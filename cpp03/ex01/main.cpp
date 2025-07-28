/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:53:20 by ego               #+#    #+#             */
/*   Updated: 2025/07/28 14:14:49 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "--- Creating ScavTrap A (SC4V-TP) ---" << std::endl;
	ScavTrap A("SC4V-TP");
	A.guardGate();
	A.attack("intruder");
	return (0);
}
