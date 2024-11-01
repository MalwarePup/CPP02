#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
}

Fixed::Fixed(const Fixed &rhs) : _rawBits(rhs._rawBits)
{
	*this = rhs;
}

Fixed::Fixed(const float value)
{
	_rawBits = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

Fixed::Fixed(const int value)
{
	_rawBits = value << _fractionalBits;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
	{
		this->_rawBits = rhs._rawBits;
	}
	return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits() const
{
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

float Fixed::toFloat() const
{
	return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
	return _rawBits >> _fractionalBits;
}

bool Fixed::operator>(const Fixed & rhs) const
{
	return this->_rawBits > rhs._rawBits;
}

bool Fixed::operator<(const Fixed & rhs) const
{
	return this->_rawBits < rhs._rawBits;
}

bool Fixed::operator>=(const Fixed & rhs) const
{
	return this->_rawBits >= rhs._rawBits;
}

bool Fixed::operator<=(const Fixed & rhs) const
{
	return this->_rawBits <= rhs._rawBits;
}

bool Fixed::operator==(const Fixed & rhs) const
{
	return this->_rawBits == rhs._rawBits;
}

bool Fixed::operator!=(const Fixed & rhs) const
{
	return this->_rawBits != rhs._rawBits;
}

Fixed Fixed::operator+(const Fixed & rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed & rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed & rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed & rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++()
{
	_rawBits++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	_rawBits++;
	return tmp;
}

Fixed &Fixed::operator--()
{
	_rawBits--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	_rawBits--;
	return tmp;
}

Fixed &Fixed::min(Fixed & a, Fixed & b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed & a, const Fixed & b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed & a, Fixed & b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed & a, const Fixed & b)
{
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
