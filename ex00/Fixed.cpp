#include "Fixed.hpp"

int const Fixed::frac_bits = 8;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(void){
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed& src){
	std::cout << "Copy constructor called" << std::endl;
	this->value = src.value;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed&	Fixed::operator=(Fixed const& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = rhs.value;

	return (*this);
}

// std::ostream&	operator<<(std::ostream& o, Fixed const& i)
// {
// 	o << "RawBits = " << i.getRawBits();
// 	return o;
// }


/*
** ----------------------------------------------------------------------------
*/

int		Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw){
	this->value = raw;
}


/* ************************************************************************** */