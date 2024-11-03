#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int _rawBits;
	static const int _fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &rhs);
	Fixed &operator=(const Fixed &rhs);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);
};

#endif /* FIXED_HPP */
