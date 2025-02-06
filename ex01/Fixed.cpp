#include "./Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	_fixedPointValue = other._fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		_fixedPointValue = other._fixedPointValue;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const int intValue) : _fixedPointValue(intValue << _fractionalBits)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float floatValue) : _fixedPointValue((int)(floatValue * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (_fixedPointValue);

};

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->_fixedPointValue = raw;
};

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