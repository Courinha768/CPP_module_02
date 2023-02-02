#include "Fixed.hpp"

int const Fixed::frac_bits = 8;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(void){
	value = 0;
}

Fixed::Fixed(const Fixed& src){
	this->value = src.value;
}

Fixed::Fixed(int const i){
	this->value = i << Fixed::frac_bits;
}

Fixed::Fixed(float const f){
	this->value = roundf(f * (1 << Fixed::frac_bits));
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed(){
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed&	Fixed::operator=(Fixed const& rhs)
{
	this->value = rhs.value;

	return (*this);
}

std::ostream&	operator<<(std::ostream& o, Fixed const& i)
{
	o << i.toFloat();
	return o;
}

bool	Fixed::operator>(Fixed const& rhs)
{
	if (this->value >= rhs.value)
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const& rhs)
{
	if (this->value <= rhs.value)
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const& rhs)
{
	if (this->value <= rhs.value)
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const& rhs)
{
	if (this->value <= rhs.value)
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const& rhs)
{
	if (this->value == rhs.value)
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const& rhs)
{
	if (this->value != rhs.value)
		return (true);
	return (false);
}

Fixed	Fixed::operator+(Fixed const& rhs)
{
	Fixed	_new(this->toFloat() + rhs.toFloat());

	return (_new);
}

Fixed	Fixed::operator-(Fixed const& rhs)
{
	Fixed	_new(this->toFloat() - rhs.toFloat());

	return (_new);
}

Fixed	Fixed::operator/(Fixed const& rhs)
{
	Fixed	_new(this->toFloat() / rhs.toFloat());

	return (_new);
}

Fixed	Fixed::operator*(Fixed const& rhs)
{
	Fixed	_new(this->toFloat() * rhs.toFloat());

	return (_new);
}

Fixed	Fixed::operator++(int)
{
	Fixed	_new;
	_new.setRawBits(value++);
	return (_new);
}

Fixed	Fixed::operator++()
{
	Fixed	_new;
	_new.setRawBits(++value);
	return (_new);
}

Fixed	Fixed::operator--(int)
{
	Fixed	_new;
	_new.setRawBits(value--);
	return (_new);
}

Fixed	Fixed::operator--()
{
	Fixed	_new;
	_new.setRawBits(--value);
	return (_new);
}

const Fixed&	Fixed::min(Fixed const& f1, Fixed const& f2)
{
	if (f1.value < f2.value)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::max(Fixed const& f1, Fixed const& f2)
{
	if (f1.value > f2.value)
		return (f1);
	return (f2);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1.value < f2.value)
		return (f1);
	return (f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1.value > f2.value)
		return (f1);
	return (f2);
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