/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:02:15 by ego               #+#    #+#             */
/*   Updated: 2025/12/14 16:43:28 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int	r = rand() % 3;

	if (r == 0)
	{
		std::cout << "Generated A" << std::endl;
		return (new A());
	}
	else if (r == 1)
	{
		std::cout << "Generated B" << std::endl;
		return (new B());
	}
	std::cout << "Generated C" << std::endl;
	return (new C());
}

void	identify(Base *p)
{
	A	*a = dynamic_cast<A *>(p);
	B	*b = dynamic_cast<B *>(p);
	C	*c = dynamic_cast<C *>(p);

	if (a)
		std::cout << "Identified A with pointer" << std::endl;
	if (b)
		std::cout << "Identified B with pointer" << std::endl;
	if (c)
		std::cout << "Identified C with pointer" << std::endl;
	return ;
}

void	identify(Base &p)
{
	bool	is_a = true;
	bool	is_b = true;
	bool	is_c = true;

	try { A	&a = dynamic_cast<A &>(p); (void)a; }
	catch (const std::exception &e) { is_a = false; }
	try { B	&b = dynamic_cast<B &>(p); (void)b; }
	catch (const std::exception &e) { is_b = false; }
	try { C	&c = dynamic_cast<C &>(p); (void)c; }
	catch (const std::exception &e) { is_c = false; }
	
	if (is_a)
		std::cout << "Identified A with reference" << std::endl;
	if (is_b)
		std::cout << "Identified B with reference" << std::endl;
	if (is_c)
		std::cout << "Identified C with reference" << std::endl;
	return ;
}

int	main(void)
{
	std::srand(std::time(0));

	Base	*unidentified_ptr = generate();
	Base	&unidentified_ref = *unidentified_ptr;

	identify(unidentified_ptr);
	identify(unidentified_ref);
	delete unidentified_ptr;
	return (0);
}
