/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 08:42:55 by oamairi           #+#    #+#             */
/*   Updated: 2026/03/05 09:09:49 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
private:
	static const int	fractional_bits = 8;
	int					fixed_point_number;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed	&operator=(const Fixed &old);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	~Fixed();
};
