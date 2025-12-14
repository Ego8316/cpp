/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:04:48 by ego               #+#    #+#             */
/*   Updated: 2025/12/14 15:56:54 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data	*data = new Data;

	data->name = "James";
	data->age = 25;
	data->height = 178;
	data->weight = 75;

	uintptr_t	raw = Serializer::serialize(data);
	Data		*check = Serializer::deserialize(raw);

	std::cout << "Original pointer = " << data << std::endl
		<< "Serialized pointer = " << raw << std::endl
		<< "Deserialized pointer = " << check << std::endl
		<< "Data before serialization: " << *data << std::endl
		<< "Data after deserialization: " << *check << std::endl;
}
