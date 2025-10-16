/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:55:14 by ego               #+#    #+#             */
/*   Updated: 2025/10/16 19:02:13 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "AMateria.hpp"

class	IMateriaSource
{
	public:
		virtual ~IMateriaSource(void) {};
		virtual void	learnMateria(AMateria *) = 0;
		virtual AMateria*	createMateria(std::string const &type) = 0;
};

