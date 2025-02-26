#include "./Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const Fixed& other)
{
	_fixedPointValue = other._fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		_fixedPointValue = other._fixedPointValue;
	return *this;
}

Fixed::~Fixed() {}

Fixed::Fixed(const int intValue) : _fixedPointValue(intValue << _fractionalBits) {}

Fixed::Fixed(const float floatValue) : _fixedPointValue((int)(floatValue * (1 << _fractionalBits))) {}

int Fixed::getRawBits(void) const
{
	return (_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

int	Fixed::toInt(void) const
{
	return (_fixedPointValue >> _fractionalBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)(_fixedPointValue) / (1 << _fractionalBits));
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixedPointNbr)
{
	return (stream << fixedPointNbr.toFloat());
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_fixedPointValue < other._fixedPointValue);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_fixedPointValue > other._fixedPointValue);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_fixedPointValue >= other._fixedPointValue);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_fixedPointValue <= other._fixedPointValue);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_fixedPointValue == other._fixedPointValue);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_fixedPointValue != other._fixedPointValue);
}

Fixed	&Fixed::operator++()
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old = *this;

	this->_fixedPointValue++;
	return (old);
}

Fixed	&Fixed::operator--()
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old = *this;

	this->_fixedPointValue--;
	return (old);
}

const Fixed	Fixed::min(Fixed const &a, Fixed const &b)
{
	
	if (a < b)
		return (a);
	return (b);
}

const Fixed	Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}
