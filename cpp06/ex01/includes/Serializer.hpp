/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:40:48 by ego               #+#    #+#             */
/*   Updated: 2025/12/14 15:57:28 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

struct	Data
{
	std::string	name;
	int			age;
	int			height;
	int			weight;
};

class	Serializer
{
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);

	private:
		Serializer(void);
		Serializer(const Serializer &src);
		Serializer	&operator=(const Serializer &src);
		~Serializer(void);
};

std::ostream	&operator<<(std::ostream &os, const Data &data);