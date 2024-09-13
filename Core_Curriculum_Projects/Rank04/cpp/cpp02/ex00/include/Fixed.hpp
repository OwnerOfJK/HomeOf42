/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:52:17 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/13 20:52:18 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    Fixed();                          // Default constructor
    Fixed(const Fixed &src);          // Copy constructor
    Fixed &operator=(const Fixed &rhs); // Copy assignment operator
    ~Fixed();                         // Destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif