#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <ostream>

class Fixed {
	private:
		int _rawBits;
		static const int _fractionalBits = 8;

	public:
		Fixed(void);
		explicit Fixed(const int n);
		explicit Fixed(const float f);
		Fixed(const Fixed &src);
		~Fixed(void);

		bool operator>=(const Fixed &src) const;
		bool operator<=(const Fixed &src) const;
		bool operator==(const Fixed &src) const;
		bool operator!=(const Fixed &src) const;
		bool operator>(const Fixed &src) const;
		bool operator<(const Fixed &src) const;

		Fixed &operator=(const Fixed &src);
		Fixed operator+(const Fixed &src);
		Fixed operator-(const Fixed &src);
		Fixed operator*(const Fixed &src);
		Fixed operator/(const Fixed &src);

		Fixed &operator++(void);
		Fixed &operator--(void);

		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);

		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

		int getRawBits(void) const;
		void setRawBits(const int raw);
		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &f);


#endif