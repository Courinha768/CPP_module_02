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

Fixed::Fixed(int const i){
	std::cout << "Int constructor called" << std::endl;
	this->value = i << Fixed::frac_bits;
}

Fixed::Fixed(float const f){
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(f * (1 << Fixed::frac_bits));
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed(){
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

std::ostream&	operator<<(std::ostream& o, Fixed const& i)
{
	o << i.toFloat();
	return o;
}

/*
** ----------------------------------------------------------------------------
*/

int		Fixed::getRawBits(void) const{
	return (this->value);
}

void	Fixed::setRawBits(int const raw){
	this->value = raw;
}

float	Fixed::toFloat(void)	const{
	return ((float)this->value / (1 << Fixed::frac_bits));	
}

int		Fixed::toInt(void)	const{
	return(this->value >> Fixed::frac_bits);
}


/* ************************************************************************** */