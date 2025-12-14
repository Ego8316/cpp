/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:04:48 by ego               #+#    #+#             */
/*   Updated: 2025/12/14 20:13:00 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Array.hpp"

int	main(void)
{
	Array<std::string>	array1(3);

	array1[0] = "salut";
	array1[1] = "ca";
	array1[2] = "va";

	std::cout << "Array: " << array1 << ", size = " << array1.size() << std::endl;
	try { array1[-1] = "null"; }
	catch (const std::exception &e) { std::cout << e.what() << std::endl; }
	try { array1[3] = "and void"; }
	catch (const std::exception &e) { std::cout << e.what() << std::endl; }

	Array<int>			array2(0);
	Array<int>			array3(2);
	Array<int>			array4(4);
	Array< Array<int> >	array5(3);

	array3[0] = 4;
	array3[1] = 2;
	array4[0] = 1;
	array4[1] = 2;
	array4[2] = 3;
	array4[3] = 4;
	array5[0] = array2;
	array5[1] = array3;
	array5[2] = array4;

	std::cout << "Array: " << array2 << ", size = " << array2.size() << std::endl;
	std::cout << "Array: " << array3 << ", size = " << array3.size() << std::endl;
	std::cout << "Array: " << array4 << ", size = " << array4.size() << std::endl;
	std::cout << "Array: " << array5 << ", size = " << array5.size() << std::endl;
}
