/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 08:47:27 by oamairi           #+#    #+#             */
/*   Updated: 2026/03/05 09:19:52 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixed_point_number = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fixed)
{
	this->fixed_point_number = fixed.fixed_point_number;
	std::cout << "Copy constructor called\n";
}

Fixed	&Fixed::operator=(const Fixed &old)
{
	if (this != &old)
		this->fixed_point_number = old.fixed_point_number;
	std::cout << "Copy assignment operator called\n";
	return *this;
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

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
