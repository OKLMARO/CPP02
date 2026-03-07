/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 08:42:55 by oamairi           #+#    #+#             */
/*   Updated: 2026/03/05 12:41:28 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

class Fixed
{
private:
	static const int	fractional_bits = 8;
	int					fixed_point_number;
public:
	Fixed();
	Fixed(const int nb);
	Fixed(const float nb);
	Fixed(const Fixed &old);

	int		toInt(void) const;
	float	toFloat(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed	&operator++();
	Fixed	&operator--();
	Fixed	&operator++(int);
	Fixed	&operator--(int);
	Fixed	&operator=(const Fixed &old);
	Fixed	operator+(const Fixed &rfixed) const;
	Fixed	operator-(const Fixed &rfixed) const;
	Fixed	operator*(const Fixed &rfixed) const;
	Fixed	operator/(const Fixed &rfixed) const;
	static Fixed	&min(Fixed &lfixed, Fixed &rfixed);
	static Fixed	&min(const Fixed &lfixed, const Fixed &rfixed);
	static Fixed	&max(Fixed &lfixed, Fixed &rfixed);
	static Fixed	&max(const Fixed &lfixed, const Fixed &rfixed);
	~Fixed();
};

constexpr bool	operator<(const Fixed &lfixed, const Fixed &rfixed);
constexpr bool	operator>(const Fixed &lfixed, const Fixed &rfixed);
constexpr bool	operator==(const Fixed &lfixed, const Fixed &rfixed);
constexpr bool	operator!=(const Fixed &lfixed, const Fixed &rfixed);
constexpr bool	operator<=(const Fixed &lfixed, const Fixed &rfixed);
constexpr bool	operator>=(const Fixed &lfixed, const Fixed &rfixed);
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);
