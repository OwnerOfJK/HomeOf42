#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    Fixed();                          // Default constructor
    Fixed(const int n);                 // Constructor with int
    Fixed(const float n);               // Constructor with float
    Fixed(const Fixed &src);          // Copy constructor
    Fixed &operator=(const Fixed &rhs); // Copy assignment operator
    ~Fixed();                         // Destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif