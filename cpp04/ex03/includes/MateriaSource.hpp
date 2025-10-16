/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:56:45 by ego               #+#    #+#             */
/*   Updated: 2025/10/16 19:02:49 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class	MateriaSource :	public	IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &src);
		MateriaSource	&operator=(const MateriaSource &src);
		~MateriaSource(void);

		void 		learnMateria(AMateria *src);
		AMateria	*createMateria(std::string const &type);

	private:
		static const int	_maxTemplates = 4;
		AMateria			*_templates[_maxTemplates];
};
