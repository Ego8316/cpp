/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:40:09 by ego               #+#    #+#             */
/*   Updated: 2025/12/18 20:24:53 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template<typename T>
class	MutantStack	:	public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &);
		MutantStack	&operator=(const MutantStack &);
		~MutantStack(void);

		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator				begin(void);
		iterator				end(void);
		const_iterator			begin(void) const;
		const_iterator			end(void) const;
		reverse_iterator		rbegin(void);
		reverse_iterator		rend(void);
		const_reverse_iterator	rbegin(void) const;
		const_reverse_iterator	rend(void) const;
};

#include "MutantStack.tpp"
