#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &rhs) : _rawBits(rhs._rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
	getRawBits();
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
	{
		this->_rawBits = rhs._rawBits;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}
