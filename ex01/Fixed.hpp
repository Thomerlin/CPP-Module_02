#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <ostream>

class Fixed {
	private:
		int _rawBits;
		static const int _fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed &src);
		~Fixed(void);

		Fixed &operator=(const Fixed &src);
		int getRawBits(void) const;
		void setRawBits(const int raw);
		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &f);


#endif