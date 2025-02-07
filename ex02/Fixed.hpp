#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int 				_fixedPointValue;
		static const int	_fractionalBits;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		~Fixed();
		Fixed(const int intValue);
		Fixed(const float floatValue);

		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int 			toInt(void) const;
		
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		Fixed	&operator++();
		Fixed	&operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		bool			operator<(const Fixed &other) const;
		bool			operator<=(const Fixed &other) const;
		bool			operator>(const Fixed &other) const;
		bool			operator>=(const Fixed &other) const;
		bool			operator==(const Fixed &other) const;
		bool			operator!=(const Fixed &other) const;

		static const Fixed&	min(Fixed const &a, Fixed const &b);
		static const Fixed&	max(Fixed const &a, Fixed const &b);
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixedPointNbr);

#endif
