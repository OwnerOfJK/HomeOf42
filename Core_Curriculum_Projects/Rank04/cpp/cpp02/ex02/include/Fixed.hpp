/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:52:53 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/20 17:03:51 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

    // Comparison operators
    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;

    // Arithmetic operators
    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;

    // Increment/Decrement operators
    Fixed &operator++();    // Pre-increment
    Fixed operator++(int);  // Post-increment
    Fixed &operator--();    // Pre-decrement
    Fixed operator--(int);  // Post-decrement

    // Static member functions
    static Fixed &min(Fixed &first, Fixed &second);
    static const Fixed &min(const Fixed &first, const Fixed &second);
    static Fixed &max(Fixed &first, Fixed &second);
    static const Fixed &max(const Fixed &first, const Fixed &second);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif