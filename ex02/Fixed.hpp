#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(int const i);
		Fixed(float const f);
		Fixed(Fixed const& src);
		~Fixed(void);
		Fixed&	operator=(Fixed const& rhs);
		bool	operator>(Fixed const& rhs);
		bool	operator<(Fixed const& rhs);
		bool	operator>=(Fixed const& rhs);
		bool	operator<=(Fixed const& rhs);
		bool	operator==(Fixed const& rhs);
		bool	operator!=(Fixed const& rhs);
		Fixed	operator+(Fixed const& rhs);
		Fixed	operator-(Fixed const& rhs);
		Fixed	operator/(Fixed const& rhs);
		Fixed	operator*(Fixed const& rhs);
		Fixed	operator++(int);
		Fixed	operator++();
		Fixed	operator--(int);
		Fixed	operator--();
		int		getRawBits(void)	const;
		void	setRawBits(int const raw);
		float	toFloat(void)	const;
		int		toInt(void)	const;
		static const Fixed&	min(Fixed const& f1, Fixed const& f2);
		static const Fixed&	max(Fixed const& f1, Fixed const& f2);
		static Fixed&	min(Fixed& f1, Fixed& f2);
		static Fixed&	max(Fixed& f1, Fixed& f2);
	private:
		int					value;
		static int const	frac_bits;
};

std::ostream& operator << (std::ostream& o, Fixed const& i);

#endif