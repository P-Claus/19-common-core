#include <iostream>

class Fixed
{
	private:
		int					_fixedPointNb;
		static const int 	_fractBits = 8;

	public:
		//constructor
		Fixed();

		//copy constructor
		Fixed(const Fixed& other);

		//copy assignment operator overload
		Fixed& operator=(const Fixed& rhs);

		//destructor
		~Fixed();

		//getter
		int		getRawBits(void) const;

		//setter
		void	setRawBits(int const raw);
};
