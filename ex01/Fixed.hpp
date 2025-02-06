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
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixedPointNbr);

#endif
