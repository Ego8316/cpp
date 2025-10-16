/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:23:58 by ego               #+#    #+#             */
/*   Updated: 2025/10/16 19:32:09 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void	testBasics(void)
{	
	std::cout << "===== BASIC TESTS =====" << std::endl;
	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter	*me = new Character("me");

	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter	*bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	std::cout << "=======================" << std::endl << std::endl;
}

void	testDeepCopy(void)
{
	std::cout << "=== DEEP COPY TESTS ===" << std::endl;
	MateriaSource	src;
	src.learnMateria(new Ice());
	src.learnMateria(new Cure());

	Character	original("Original");
	original.equip(src.createMateria("ice"));
	original.equip(src.createMateria("cure"));

	std::cout << "Original uses materias:" << std::endl;
	original.use(0, original);
	original.use(1, original);

	std::cout << "Copy uses materias:" << std::endl;
	Character	copy(original);
	copy.use(0, copy);
	copy.use(1, copy);

	std::cout << "After unequip in copy:" << std::endl;
	AMateria	*m = copy.getMateria(0);
	copy.unequip(0);
	delete m;
	copy.use(0, copy);
	original.use(0, original);
	std::cout << "=======================" << std::endl << std::endl;
}

void	testEdgeCases(void)
{
	std::cout << "=== EDGE CASE TESTS ===" << std::endl;
	MateriaSource	src;
	src.learnMateria(new Ice());
	src.learnMateria(new Cure());
	Character me("EdgeTester");
	for (int i = 0; i < 5; ++i)
	{
		AMateria *tmp = src.createMateria(i % 2 == 0 ? "ice" : "cure");
		me.equip(tmp);
		if (i == 4)
			delete tmp;
	}
	me.equip(NULL);
	me.use(-1, me);
	me.use(10, me);
	me.unequip(-2);
	me.unequip(99);
	AMateria	*m = me.getMateria(2);
	me.unequip(2);
	delete m;
	me.use(2, me);
	AMateria *unknown = src.createMateria("fire");
	(void)unknown;
	std::cout << "=======================" << std::endl << std::endl;
}

int	main(void)
{
	testBasics();
	testDeepCopy();
	testEdgeCases();
	return (0);
}
