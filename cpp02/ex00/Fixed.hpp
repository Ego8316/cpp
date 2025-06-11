/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 23:48:32 by ego               #+#    #+#             */
/*   Updated: 2025/06/12 00:17:48 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int					_rawBits;
		static const int	_fractionalBits;
	
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);
		Fixed	&operator=(Fixed const &src);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif