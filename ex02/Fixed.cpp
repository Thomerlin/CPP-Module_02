#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(const int n)
{
	this->_rawBits = n << this->_fractionalBits;
}

Fixed::Fixed(const float f)
{
	this->_rawBits = roundf(f * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::~Fixed(void) {}

Fixed &Fixed::operator=(const Fixed &src)
{
	this->setRawBits(src.getRawBits());
	return (*this);
}

bool Fixed::operator>(const Fixed &src) const
{
	return (this->getRawBits() > src.getRawBits());
}

bool Fixed::operator<(const Fixed &src) const
{
	return (this->getRawBits() < src.getRawBits());
}

bool Fixed::operator>=(const Fixed &src) const
{
	return (this->getRawBits() >= src.getRawBits());
}

bool Fixed::operator<=(const Fixed &src) const
{
	return (this->getRawBits() <= src.getRawBits());
}

bool Fixed::operator==(const Fixed &src) const
{
	return (this->getRawBits() == src.getRawBits());
}

bool Fixed::operator!=(const Fixed &src) const
{
	return (this->getRawBits() != src.getRawBits());
}

Fixed Fixed::operator+(const Fixed &src)
{
	Fixed res = Fixed();

	res.setRawBits(this->getRawBits() + src.getRawBits());
	return (res);
}

Fixed Fixed::operator-(const Fixed &src)
{
	Fixed res = Fixed();

	res.setRawBits(this->getRawBits() - src.getRawBits());
	return (res);
}

Fixed Fixed::operator*(const Fixed &src)
{
	int _rawBits;
	Fixed res = Fixed();

	_rawBits = this->getRawBits() * src.getRawBits();
	_rawBits >>= 8;
	res.setRawBits(_rawBits);
	return (res);
}

Fixed Fixed::operator/(const Fixed &src)
{
	int _rawBits;
	Fixed res = Fixed();

	_rawBits = this->getRawBits() << 8;
	_rawBits /= src.getRawBits();
	res.setRawBits(_rawBits);
	return (res);
}

Fixed &Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed copy = *this;

	this->setRawBits(this->getRawBits() + 1);
	return (copy);
}

Fixed Fixed::operator--(int)
{
	Fixed copy = *this;

	this->setRawBits(this->getRawBits() - 1);
	return (copy);
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

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

std::ostream &operator<<(std::ostream &out, Fixed const &f)
{
	out << f.toFloat();
	return (out);
}
