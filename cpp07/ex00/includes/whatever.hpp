/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:12:34 by ego               #+#    #+#             */
/*   Updated: 2025/12/14 17:32:10 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> void	swap(T &a, T &b)
{
	T	c = a;
	a = b;
	b = c;
	return ;
}

template <typename T> const T	&min(const T &a, const T &b)
{
	return (a < b ? a : b);
}

template <typename T> const T	&max(const T &a, const T &b)
{
	return (a > b ? a : b);
}
