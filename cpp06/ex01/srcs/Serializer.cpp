/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:41:05 by ego               #+#    #+#             */
/*   Updated: 2025/12/14 15:59:09 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Private constructors and destructor

Serializer::Serializer(void) { }
Serializer::Serializer(const Serializer &src) { (void)src; }
Serializer	&Serializer::operator=(const Serializer &src) { return ((void)src, *this); }
Serializer::~Serializer(void) { }

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

std::ostream	&operator<<(std::ostream &os, const Data &data)
{
	os << "{Name: " << data.name << ", Age: " << data.age
		<< ", Height: " << data.height << ", Weight: " << data.weight << "}";
	return (os);
}