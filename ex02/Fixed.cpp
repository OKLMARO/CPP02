/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 08:47:27 by oamairi           #+#    #+#             */
/*   Updated: 2026/03/08 14:38:26 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int getPower(int x, int n)
{
	int	mult = 1;
	for (int i = 0; i < n; i++)
	{
		mult = mult * x;
	}
	return mult;
}

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
	int mult = getPower(2, fractional_bits);
	this->fixed_point_number = nb * mult;
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float nb)
{
	int mult = getPower(2, fractional_bits);
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
	int mult = getPower(2, fractional_bits);
	return this->fixed_point_number / mult;
}

float	Fixed::toFloat(void) const
{
	int mult = getPower(2, fractional_bits);
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

bool	operator==(const Fixed &lfixed, const Fixed &rfixed)
{
	if (lfixed.toFloat() == rfixed.toFloat())
		return true;
	return false;
}

bool	operator!=(const Fixed &lfixed, const Fixed &rfixed)
{
	if (lfixed.toFloat() != rfixed.toFloat())
		return true;
	return false;
}

bool	operator<(const Fixed &lfixed, const Fixed &rfixed)
{
	if (lfixed.toFloat() < rfixed.toFloat())
		return true;
	return false;
}

bool	operator>(const Fixed &lfixed, const Fixed &rfixed)
{
	if (lfixed.toFloat() > rfixed.toFloat())
		return true;
	return false;
}

bool	operator<=(const Fixed &lfixed, const Fixed &rfixed)
{
	if (lfixed.toFloat() <= rfixed.toFloat())
		return true;
	return false;
}

bool	operator>=(const Fixed &lfixed, const Fixed &rfixed)
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

Fixed	Fixed::operator++(int)
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

Fixed	Fixed::operator--(int)
{
	Fixed current = *this;
	this->fixed_point_number = this->fixed_point_number - 1;
	return current;
}

Fixed	Fixed::operator+(const Fixed &rfixed) const
{
	return Fixed(this->toFloat() + rfixed.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rfixed) const
{
	return Fixed(this->toFloat() - rfixed.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rfixed) const
{
	return Fixed(this->toFloat() * rfixed.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rfixed) const
{
	if (this->fixed_point_number == 0 || rfixed.fixed_point_number == 0)
	{
		std::cout << "Error dived by 0 !\n";
		return (Fixed(0));
	}
	return Fixed(this->toFloat() / rfixed.toFloat());
}

Fixed	&Fixed::min(Fixed &lfixed, Fixed &rfixed)
{
	if (lfixed.fixed_point_number > rfixed.fixed_point_number)
		return rfixed;
	return lfixed;
}

const Fixed	&Fixed::min(const Fixed &lfixed, const Fixed &rfixed)
{
	if (lfixed.fixed_point_number > rfixed.fixed_point_number)
		return rfixed;
	return lfixed;
}

Fixed	&Fixed::max(Fixed &lfixed, Fixed &rfixed)
{
	if (lfixed.fixed_point_number < rfixed.fixed_point_number)
		return rfixed;
	return lfixed;
}

const Fixed	&Fixed::max(const Fixed &lfixed, const Fixed &rfixed)
{
	if (lfixed.fixed_point_number < rfixed.fixed_point_number)
		return rfixed;
	return lfixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
