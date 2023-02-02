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
		Fixed	&operator=(Fixed const& rhs);
		int		getRawBits(void)	const;
		void	setRawBits(int const raw);
		float	toFloat(void)	const;
		int		toInt(void)	const;
	private:
		int					value;
		static int const	frac_bits;
};

std::ostream& operator << (std::ostream& o, Fixed const& i);

#endif