/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:11:46 by hcavet            #+#    #+#             */
/*   Updated: 2025/12/17 14:15:18 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	Span
{
	public:
		Span(void);
		Span(const unsigned int);
		Span(const Span &);
		Span	&operator=(const Span &);
		~Span(void);

		void	addNumber(int);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

	private:
		const unsigned int	_N;
		int
};