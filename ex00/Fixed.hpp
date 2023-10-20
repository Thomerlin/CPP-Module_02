#ifndef FIXED_HPP_
#define FIXED_HPP_

class Fixed {
	private:
		int _rawBits;
		static const int _fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &src);
		~Fixed(void);

		Fixed &operator=(const Fixed &src);
		int getRawBits(void) const;
		void setRawBits(const int raw);
};


#endif