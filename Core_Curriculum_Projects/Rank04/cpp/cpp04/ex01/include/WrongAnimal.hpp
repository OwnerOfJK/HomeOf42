/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:52:58 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/15 18:52:59 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_HPP
#define WrongAnimal_HPP

#include <iostream>

class WrongAnimal {
    public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &src);
    WrongAnimal &operator=(const WrongAnimal &rhs);
    ~WrongAnimal();
    const std::string &getType() const;
    void makeSound() const;

    protected:
    std::string type;
};

#endif