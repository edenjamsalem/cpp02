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
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		Fixed(const int intValue);
		Fixed(const float floatValue);

		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int 			toInt(void) const;
		
		Fixed	operator+(const Fixed& other);
		Fixed	operator-(const Fixed& other);
		Fixed	operator*(const Fixed& other);
		Fixed	operator/(const Fixed& other);

		Fixed	operator++();
		Fixed&	operator++(int);
		Fixed	operator--();
		Fixed&	operator--(int);

		bool			operator<(const Fixed& other);
		bool			operator<=(const Fixed& other);
		bool			operator>(const Fixed& other);
		bool			operator>=(const Fixed& other);
		bool			operator==(const Fixed& other);
		bool			operator!=(const Fixed& other);

		Fixed&	min(Fixed& a, Fixed& b);
		Fixed&	max(Fixed& a, Fixed& b);
		Fixed&	min(const Fixed& a, const Fixed& b);
		Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixedPointNbr);

#endif
