/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:41:21 by ego               #+#    #+#             */
/*   Updated: 2025/12/18 20:26:39 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
	:	std::stack<T>()
{
	return ;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src)
	:	std::stack<T>(src)
{
	return ;
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &src)
{
	if (this != &src)
		std::stack<T>::operator=(src);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	return ;
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin(void)
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend(void)
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin(void) const
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend(void) const
{
	return (this->c.rend());
}
