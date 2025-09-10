/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:14:24 by ego               #+#    #+#             */
/*   Updated: 2025/09/10 13:20:44 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define HOUSE_SIZE 6

void	testArray(void)
{
	std::cout << "Array test" << std::endl;
	Animal	*house[HOUSE_SIZE + 1];
	house[HOUSE_SIZE] = NULL;
	for (int i = 0; i < HOUSE_SIZE; ++i)
	{
		if (i % 2)
			house[i] = new Cat();
		else
			house[i] = new Dog();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < HOUSE_SIZE; ++i)
		house[i]->makeSound();
	std::cout << std::endl;
	for (int i = 0; i < HOUSE_SIZE; ++i)
	{
		delete house[i];
		std::cout << std::endl;
	}
	return ;
}

void	testCatCopy(void)
{
	std::cout << "Cat copy test" << std::endl;
	Cat	*cat = new Cat();
	std::cout << std::endl;
	cat->getBrain()->setIdea(0, "Let's slap some things");
	cat->getBrain()->setIdea(1, "I got da zoomies");
	cat->getBrain()->setIdea(2, "How about a nap?");
	std::cout << std::endl << "Original cat ideas:" << std::endl;
	for (int i = 0; i < 3; ++i)
		cat->getBrain()->sayIdea(i);
	std::cout << std::endl << "Creating a copy of the cat (a copycat?)" << std::endl;
	Cat	*copy = new Cat(*cat);
	std::cout << std::endl << "Copy cat ideas before changing anything:" << std::endl;
	for (int i = 0; i < 3; ++i)
		copy->getBrain()->sayIdea(i);
	std::cout << std::endl << "Changing copy cat ideas" << std::endl;
	copy->getBrain()->setIdea(0, "Jeez the human hasnt fed me for 20 minutes I swear he wants me to starve");
	copy->getBrain()->setIdea(1, "That toilet water is lookin really sweet right now");
	copy->getBrain()->setIdea(2, "Yeah I scratched the couch, what are you gonna do about it? Gonna cry?");
	std::cout << std::endl << "Original cat ideas after changing copy:" << std::endl;
	for (int i = 0; i < 3; ++i)
		cat->getBrain()->sayIdea(i);
	std::cout << std::endl << "Copy cat ideas after changing copy:" << std::endl;
	for (int i = 0; i < 3; ++i)
		copy->getBrain()->sayIdea(i);
	std::cout << std::endl;
	delete cat;
	delete copy;
	return ;
}

void	testDogCopy(void)
{
	std::cout << "dog copy test" << std::endl;
	Dog	*dog = new Dog();
	std::cout << std::endl;
	dog->getBrain()->setIdea(0, "Let's slap some things");
	dog->getBrain()->setIdea(1, "I got da zoomies");
	dog->getBrain()->setIdea(2, "How about a nap?");
	std::cout << std::endl << "Original dog ideas:" << std::endl;
	for (int i = 0; i < 3; ++i)
		dog->getBrain()->sayIdea(i);
	std::cout << std::endl << "Creating a copy of the dog" << std::endl;
	Dog	*copy = new Dog(*dog);
	std::cout << std::endl << "Copy dog ideas before changing anything:" << std::endl;
	for (int i = 0; i < 3; ++i)
		copy->getBrain()->sayIdea(i);
	std::cout << std::endl << "Changing copy dog ideas" << std::endl;
	copy->getBrain()->setIdea(0, "Jeez the human hasnt fed me for 20 minutes I swear he wants me to starve");
	copy->getBrain()->setIdea(1, "That toilet water is lookin really sweet right now");
	copy->getBrain()->setIdea(2, "Yeah I scratched the couch, what are you gonna do about it? Gonna cry?");
	std::cout << std::endl << "Original dog ideas after changing copy:" << std::endl;
	for (int i = 0; i < 3; ++i)
		dog->getBrain()->sayIdea(i);
	std::cout << std::endl << "Copy dog ideas after changing copy:" << std::endl;
	for (int i = 0; i < 3; ++i)
		copy->getBrain()->sayIdea(i);
	std::cout << std::endl;
	delete dog;
	delete copy;
	return ;
}

int	main(void)
{
	testArray();
	testCatCopy();
	testDogCopy();
	// Animal	*beast = new Animal();
}
