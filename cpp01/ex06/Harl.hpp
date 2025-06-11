/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:38:38 by ego               #+#    #+#             */
/*   Updated: 2025/06/11 22:15:41 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define DEBUG_MSG "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
# define INFO_MSG "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
# define WARNING_MSG "[ WARNING ]\nI think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month."
# define ERROR_MSG "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now."
# define DEFAULT_MSG "[ Probably complaining about insignificant problems ]"

class	Harl
{
	private:
		static const char	*_levels[];
		void				_debug(void) const;
		void				_info(void) const;
		void				_warning(void) const;
		void				_error(void) const;

	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

#endif
