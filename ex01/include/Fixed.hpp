#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _rawBits;
	static const int _fractionalBits = 8;
public:
	Fixed();
	Fixed(const float value);
	Fixed(const int value);
	Fixed(const Fixed &rhs);
	Fixed &operator=(const Fixed &rhs);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);

	float toFloat() const;
	int toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif /* FIXED_HPP */
