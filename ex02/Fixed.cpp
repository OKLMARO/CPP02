/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 08:47:27 by oamairi           #+#    #+#             */
/*   Updated: 2026/03/05 12:41:42 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixed_point_number = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &old)
{
	std::cout << "Copy constructor called\n";
	*this = old;
}

Fixed::Fixed(const int nb)
{
	int	mult = 1;
	for (size_t i = 0; i < fractional_bits; i++)
	{
		mult = mult * 2;
	}
	this->fixed_point_number = nb * mult;
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float nb)
{
	int	mult = 1;
	for (size_t i = 0; i < fractional_bits; i++)
	{
		mult = mult * 2;
	}
	this->fixed_point_number = roundf(nb * mult);
	std::cout << "Float constructor called\n";
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return this->fixed_point_number;
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point_number = raw;
}

int		Fixed::toInt(void) const
{
	int	mult = 1;
	for (size_t i = 0; i < fractional_bits; i++)
	{
		mult = mult * 2;
	}
	return this->fixed_point_number / mult;
}

float	Fixed::toFloat(void) const
{
	int	mult = 1;
	for (size_t i = 0; i < fractional_bits; i++)
	{
		mult = mult * 2;
	}
	return (float) this->fixed_point_number / mult;
}

Fixed	&Fixed::operator=(const Fixed &old)
{
	if (this != &old)
		this->fixed_point_number = old.fixed_point_number;
	std::cout << "Copy assignment operator called\n";
	return *this;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

constexpr bool	operator==(const Fixed &lfixed, const Fixed &rfixed)
{
	if (lfixed.toFloat() == rfixed.toFloat())
		return true;
	return false;
}

constexpr bool	operator!=(const Fixed &lfixed, const Fixed &rfixed)
{
	if (lfixed.toFloat() != rfixed.toFloat())
		return true;
	return false;
}

constexpr bool	operator<(const Fixed &lfixed, const Fixed &rfixed)
{
	if (lfixed.toFloat() < rfixed.toFloat())
		return true;
	return false;
}

constexpr bool	operator>(const Fixed &lfixed, const Fixed &rfixed)
{
	if (lfixed.toFloat() > rfixed.toFloat())
		return true;
	return false;
}

constexpr bool	operator<=(const Fixed &lfixed, const Fixed &rfixed)
{
	if (lfixed.toFloat() <= rfixed.toFloat())
		return true;
	return false;
}

constexpr bool	operator>=(const Fixed &lfixed, const Fixed &rfixed)
{
	if (lfixed.toFloat() >= rfixed.toFloat())
		return true;
	return false;
}

Fixed	&Fixed::operator++()
{
	this->fixed_point_number = this->fixed_point_number + 1;
	return *this;
}

Fixed	&Fixed::operator++(int)
{
	Fixed current = *this;
	this->fixed_point_number = this->fixed_point_number + 1;
	return current;
}

Fixed	&Fixed::operator--()
{
	this->fixed_point_number = this->fixed_point_number - 1;
	return *this;
}

Fixed	&Fixed::operator--(int)
{
	Fixed current = *this;
	this->fixed_point_number = this->fixed_point_number - 1;
	return current;
}

Fixed	Fixed::operator+(const Fixed &rfixed) const
{
	return this->fixed_point_number + rfixed.fixed_point_number;
}

Fixed	Fixed::operator-(const Fixed &rfixed) const
{
	return this->fixed_point_number - rfixed.fixed_point_number;
}

Fixed	Fixed::operator*(const Fixed &rfixed) const
{
	return this->fixed_point_number * rfixed.fixed_point_number;
}

Fixed	Fixed::operator/(const Fixed &rfixed) const
{
	return this->fixed_point_number / rfixed.fixed_point_number;
}

Fixed	&Fixed::min(Fixed &lfixed, Fixed &rfixed)
{
	
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
