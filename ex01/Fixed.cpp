#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = n << this->_fractionalBits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(f * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(src.getRawBits());
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(const int raw)
{
	this->_rawBits = raw;
}

int Fixed::toInt(void) const
{
	return (this->_rawBits >> this->_fractionalBits);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_rawBits) / (1 << this->_fractionalBits));
}

std::ostream &operator<<(std::ostream &out, Fixed const &f)
{
	out << f.toFloat();
	return (out);
}